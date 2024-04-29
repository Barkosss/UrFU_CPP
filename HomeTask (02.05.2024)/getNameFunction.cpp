#include<iostream>
#include<fstream>
#include<string>

#include "getNameFunction.h"

std::ifstream readFile("functions.cpp");
std::ofstream functionFile("function.barsik");
std::ofstream recursiveFunctionFile("recursiveFunction.barsik");

// Массив из наименований тип данных (Стандартные + struct + class + другие)
unsigned long long counterDataType = 10;
std::string* arrayDataType = new std::string[counterDataType]{
    "void",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "long long",
    "unsigned long long",
    "double",
    "float",
    "long double"
};

// Получить последнии index символов строки
std::string back(std::string& str, unsigned long long slice) {
    std::string result = "";
    unsigned long long stringLength = str.length();
    for(unsigned long long index = stringLength - slice; index < stringLength; index++) {
        result += str[index];
    }
    return result;
}

// Проверить, есть ли в списке тип данных
bool is(std::string& type) {
    for(unsigned long long index = 0; index < counterDataType; index++) {
        if (arrayDataType[index] == type) {
            return true;
        }
    }
    return false;
}

// Получить слово по индексу (разделитель - пробел)
std::string getWord(std::string& str, unsigned long long indexWord) {
    std::string word = "";
    unsigned long long counterSpace = 0, index = 0;

    for(;counterSpace < indexWord; index++) {
        if (str[index] == ' ') {
            counterSpace++;
        }
    }

    while(str[index] != ' ') {
        word += str[index++];
    }
    return word;
}

// Парсер строки
void parse(std::string line) {
    std::cout << 1 << std::endl;
    std::string type = getWord(line, 0);
    std::cout << 2 << ": " << type << std::endl;
    // Если есть тип данных -> Далее проверяем строку
    if (is(type)) {
        std::cout << 3 << std::endl;
        std::string function = getWord(line, 1);
        std::cout << 4 << ": " << function << std::endl;
        // Если последнии два символа у function равны "()" --> Название функции.
        //std::cout << "Back: " << back(function, 2) << std::endl;
        if (back(function, 2) == "()") {
            std::cout << 5 << ": " << function << std::endl;
            functionFile << function << std::endl;
            // ...
            // ...
            // ...
        }
    };
};


// Убираем лишние пробелы в строке
std::string trim(std::string str) {

    std::string trimString = "";
    unsigned long long index = 0;
    while(str[index]) {
        if (str[index] == ' ') {
            index++;
        } else if (trimString.length() && str[index] != ' ' && str[index - 1] == ' ') {
            trimString = trimString + ' ' + str[index++];
        } else {
            trimString += str[index++];
        }
    }
    return trimString;
}


// Основная функция
void getNameFunction() {

    // Не удалось открыть файл
    if (!readFile.is_open()) {
        return;
    };

    std::string line;
    while(!readFile.eof()) {
        std::getline(readFile, line);
        
        if (!line.length()) continue;

        // Убираем лишнии пробелы (Оставляем только один пробел между словами)
        line = trim(line);

        // Отправляем на обработку
        //std::cout << line << std::endl;
        parse(line);
    }
};
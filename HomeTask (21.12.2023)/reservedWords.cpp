#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Задание #2

// Определение длины строки
long long LengthString(string word) {
    long long resultLength = 0;
    for(int i = 0; word[i] != '\0'; i++) resultLength++;
    return resultLength;
}


// Функция для посимвольной проверки полученного слова и зарез. слова
bool CheckStrings(string textWord, string resWord) {
    long textWordLength = textWord.length(); long resWordLength = resWord.length();

    // Если длина строк не совпало
    if (textWordLength != resWordLength) return false;

    for (int index = 0; index < textWordLength; index++)
        // Если какой-то символ не совпал
        if (textWord[index] != resWord[index]) return false;

    // Если все символы совпали
    return true;
}

// Функция для возведения в степень
long long Degree(long long number, long long degree) {
    long long result = 1;
    for (int i = 0; i < degree; i++) result *= result;
    return result;
}

// Функция для вычисления хэша у строки
long long HashCalc(string word, int wordLength) {
    long long resultHashe = 0;
    for(int index = 0; index < wordLength; index++) resultHashe += (int)word[index] * Degree(wordLength - index - 1, 2);
    return resultHashe;
}

int main() {
    std::ifstream reservFile("reservedwords.txt"); // Файл с зарезервированными словами
    std::ifstream textFile("text.txt"); // Файл с текстом
    std::ifstream resultFile("reservedWordsResult.txt"); // Файл с результатом
    string* hashesWords = new string[0];

    // Если не получилось открыть файл с зарезервированными словами
    if (!reservFile.is_open()) {
        cout << "File with reserved words not found" << endl;
        return 0;
    }
    // Если не получилось открыть файл с текстом
    if (!textFile.is_open()) {
        cout << "Text file not found" << endl;
        return 0;
    }

    // Вычисление хэшей у зарезервированных слов
    string word; long long longHashesSum = 0; int wordLength;
    while (!reservFile.eof()) {
        reservFile >> word; // Зарезервированное слово
        wordLength = word.length(); // Длина строки

        // Вычисляем сумму
        longHashesSum = HashCalc(word, wordLength);

        hashesWords[longHashesSum] = word; // Сохраняем в индексе, который равен сумме хэшей, зарез. слово
        longHashesSum = 0; // Обнуляем сумму хэшей
    }

    // Проход по файлу с текстом
    while (!textFile.eof()) {
        textFile >> word;
        wordLength = word.length();

        // Вычисляем сумму
        longHashesSum = HashCalc(word, wordLength);

        cout << "Word: " << word << " | Hashes: " << longHashesSum << endl;
        // Если не найдено зарезервированное слово или не совпали строки
        if (LengthString(hashesWords[longHashesSum]) || CheckStrings(word, hashesWords[longHashesSum])) continue;

        cout << "Find word: " << word << endl;
    }
    return 0;
}
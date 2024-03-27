#include<iostream>
#include<fstream>
#include<string>

#include "fileSystem.h"
#include "List.h"

using std::string;

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {
    std::ifstream reservedWord("words.txt");

    List counterWords;

    // Чтение зарезервированных слов
    string word;
    while(!reservedWord.eof()) {
        reservedWord >> word;
        counterWords.push(word);
    }

    // Счётчик
    while(!readFile.eof()) {
        readFile >> word;
        counterWords.add(word);
    }

    // Сортировка
    counterWords.sort();

    // Вывод
    counterWords.print(writeFile);
    reservedWord.close();
    std::cout << "Exit programm" << std::endl;
}
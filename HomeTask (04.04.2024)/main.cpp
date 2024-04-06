#include<iostream>
#include<fstream>
#include<string>

#include "Sentence.h"

using std::string;

int main() {
    std::ifstream readFile("text.txt");

    if (!readFile.is_open()) {
        std::cout << "Error: File is not open" << std::endl;
        return -1;
    }

    List text = List();

    char lastChar;
    unsigned long counterWords = 0, lengthWord;
    string *array = new string[counterWords + 1]; string word, wordToLower;

    // Читаем слова и предложения
    while(!readFile.eof()) {
        std::cout << 1 << std::endl;
        readFile >> word;
        std::cout << 1.2 << std::endl;
        wordToLower = "";
        lengthWord = word.length();

        std::cout << 1.3 << std::endl;
        // Перевод слова в нижний регистр
        /*
        for(int index = 0; index < lengthWord; index++) {
            if (65 <= word[index] && word[index] <= 90) {
                wordToLower += (char)(word[index] + 32);
                continue;
            }

            wordToLower += word[index];
        }
        */

        for(int index = 0; word[index]; index++) {
            wordToLower += ((65 <= word[index] && word[index] <= 90) ? ((char)(word[index] + 32)) : (word[index]));
        }

        std::cout << 1.4 << std::endl;

        lastChar = word[lengthWord - 1];
        std::cout << 1.44 << std::endl;
        // Если конец предложения
        if (lastChar == '.' || lastChar == '!' || lastChar == '?' || lastChar == ':' || lastChar == ';') {
            std::cout << 1.5 << std::endl;
            word.pop_back();
            array[counterWords] = wordToLower;
            std::cout << 1.6 << std::endl;

            // Удаление слов
            /*
            for(int index = 0; index < counterWords; index++) {
                delete[] array;
            }
            delete array;
            */
            std::cout << 1.7 << std::endl;

            text.push(array, counterWords);
            counterWords = 0;
        }

        // Если не конец предложения
        else {
            std::cout << 1.45 << std::endl;
            array[counterWords++] = wordToLower;
            std::cout << 1.46 << std::endl;
        }
    }

    readFile.close();
    return 0;
}
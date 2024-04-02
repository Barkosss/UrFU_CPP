#include<fstream>
#include<string>

#include "Sentence.h"

using std::string;

int main() {
    std::ifstream readFile("text.txt");

    Sentence *sentence = new Sentence();

    char lastChar;
    unsigned long counterWords = 0, lengthWord;
    string* array; string word, wordToLower;

    // Читаем слова и предложения
    while(!readFile.eof()) {
        readFile >> word;
        wordToLower = "";
        lengthWord = word.length();

        // Перевод слова в нижний регистр
        for(int index = 0; index < lengthWord; index++) {
            if (65 <= word[index] && word[index] <= 90) {
                wordToLower += (char)(word[index] + 32);
            }
        }

        lastChar = word[lengthWord - 1];
        // Если конец предложения
        if (lastChar == '.' || lastChar == '!' || lastChar == '?' || lastChar == ':' || lastChar == ';') {
            Sentence currSentence;

            word.pop_back();
            array[counterWords] = wordToLower;

            // Удаление слов
            for(int index = 0; index < counterWords; index++) {
                delete[] array;
            }
            delete array;
            currSentence.push(array, counterWords);
            counterWords = 0;
        }

        // Если не конец предложения
        else {
            array[counterWords++] = wordToLower;
        }
    }

    return 0;
}
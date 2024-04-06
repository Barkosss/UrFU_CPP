#include<iostream>
#include<fstream>
#include<string>

#include "Sentence.h"

using std::string;

struct Word {
    string word;
    Word* next;

    Word(): word(NULL), next(nullptr) {};
    Word(string word): word(word), next(nullptr) {};
};

class Array {
private:
    Word* first;
    Word* last;

public:
    Array(): first(nullptr), last(nullptr) {};

    // Добавить слово
    void add(string word,  bool isEndSentence = false, unsigned long counterWords = 0) {
        Word *ptr = new Word(word);

        // Если список пуст
        if (is_empty()) {
            first = ptr;
            last = ptr;
        }
        last->next = ptr;
        last = ptr;

        // Если конец предложения
        if (isEndSentence) {
            Sentence *ptrList = new Sentence(counterWords);
            ptrList->push(word);
        }
    }

    // Очистить список
    void clear() {
        // --- Временный костыль ---
        first = nullptr;
        last = nullptr;
        // --- Временный костыль ---
    }

    // Проверка, пустой ли список
    bool is_empty() {
        return first == nullptr;
    }
};


// Конец предложения: .!?;:()
// Отделены слова: (Пробелом), и другими символами
// Слова: Буквы и ' (Апостроф)

int main() {
    std::ifstream readFile("text.txt");

    if (readFile.fail()) {
        std::cout << "Error: File is not open" << std::endl;
        return -1;
    }


    unsigned long counterWords = 0;
    char lastChar; string word, wordToLower;
    Array arrayWord = Array();

    while(!readFile.eof()) {
        readFile >> word;
        wordToLower = "";
        counterWords++;

        for(int index = 0; word[index]; index++) {
            wordToLower += (char)(word[index] + 32 * (65 <= word[index] && word[index] <= 90));
        }

        lastChar = wordToLower.back();

        // Если конец предложения
        if (lastChar == '.' || lastChar == '!' || lastChar == '?' || lastChar == ':' || lastChar == ';') {
            wordToLower.pop_back();

            arrayWord.add(wordToLower, true, counterWords);
            arrayWord.clear();
            counterWords = 0;
        }

        // Если не конец предложения
        else {
            arrayWord.add(wordToLower);
        }
    }

    return 0;
}
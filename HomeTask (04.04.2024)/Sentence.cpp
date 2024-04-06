#include<iostream>
#include<fstream>

#include "Sentence.h"

using std::string;

// Проверка, пустой ли список
bool List::is_empty() {
    return firstSentence == nullptr;
}

// Проверка, пустой ли список
bool List::Sentence::is_empty() {
    return firstWord == nullptr;
}

void List::Sentence::add(string *arrWords, unsigned long counterWords) {

    std::cout << 2.6 << std::endl;
    for(int index = 0; index < counterWords; index++) {
        Word* newWord = new Word(arrWords[index]);
        std::cout << 2.7 << std::endl;
        if (is_empty()) {
            firstWord = newWord;
            lastWord = newWord;
        }

        lastWord->next = newWord;
        lastWord = newWord;
        std::cout << 2.8 << std::endl;
    }
}

void List::push(string *arrayWords, unsigned long counterWords) {
    Sentence *sentence = new Sentence();

    std::cout << 2 << std::endl;
    if (is_empty()) {
        firstSentence = sentence;
        lastSentence = sentence;
    }
    std::cout << 2.5 << std::endl;
    sentence->counterWords = counterWords;
    sentence->add(arrayWords, counterWords);
    std::cout << 2.9 << std::endl;

    lastSentence->next = sentence;
    lastSentence = sentence;
    std::cout << 3 << std::endl;
}

void List::print() {
    std::ofstream writeFile("result.txt");
    unsigned long indexSentence = 0;
    Sentence* ptrSentence = this->firstSentence;
    while(ptrSentence->next) {
        std::cout << "Sentence #" << indexSentence + 1 << ": ";
        writeFile << "Sentence #" << indexSentence + 1 << ": ";

        Word* ptrWord = ptrSentence->firstWord;
        for(int indexWord = 0; ptrSentence->counterWords; indexWord++) {
            std::cout << ptrWord->word << " | ";
            writeFile << ptrWord->word << " | ";

            ptrWord = ptrWord->next;
        }

        indexSentence++;
        ptrSentence = ptrSentence->next;

        std::cout << std::endl;
        writeFile << std::endl;
    }

    std::cout << "Program is exit" << std::endl;
}
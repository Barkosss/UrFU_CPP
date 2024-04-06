#include<iostream>
#include<fstream>

#include "Sentence.h"

bool Sentence::is_empty() {
    return firstWord == nullptr;
}

bool List::is_empty() {
    return firstSentence == nullptr;
}

// Добавить новое предложение
void Sentence::push(string word) {
    Word *ptrWord = new Word(word);

    if (is_empty()) {
        firstWord = ptrWord;
        lastWord = ptrWord;
    }

    ptrWord->prevWord = lastWord->prevWord;
    lastWord = ptrWord;
}
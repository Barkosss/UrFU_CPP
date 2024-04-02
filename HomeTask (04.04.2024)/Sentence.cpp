#include<string>

#include "Sentence.h"

using std::string;

// Проверка, пустой ли список
bool Sentence::is_empty() {
    return firstSentence == nullptr;
}

void Sentence::push(string *arrayWords, unsigned long counterWords) {
    
    for(int indexWord = 0; indexWord < counterWords; indexWord++) {
        Word *word = new Word(arrayWords[indexWord]);

        // Если список предложений пуст
        if (is_empty()) {

        }

        // Если список предложений не пуст
        else {
            
        }
    }
}
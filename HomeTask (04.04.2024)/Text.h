#pragma once

struct Word {
    string word;
    unsigned long length;

    Word* nextWord;
    Word(string word): word(word), length(word.length), nextWord(nullptr) {};
};

struct Sentence {
    Word* words;
    unsigned long countWords;

    Sentence* nextSentence;
    Sentence(Word* words, unsigned long countWords): words(words), countWords(countWords), nextSentence(nullptr) {};
};


class Text() {
private:


public:
    Sentence(): {};
    void push(String word);

}
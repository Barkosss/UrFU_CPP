#pragma once

#include<string>

using std::string;

struct Word {
    string word;

    Word* nextWord;
    Word* prevWord;

    Word(string word): word(word), nextWord(nullptr), prevWord(nullptr) {};
};

struct Sentence {
    unsigned long counterWords;
    Word* firstWord;
    Word* lastWord;

    Sentence* nextSentence;
    Sentence* prevSentence;

    Sentence(unsigned long counterWords): counterWords(counterWords), firstWord(nullptr), lastWord(nullptr), nextSentence(nullptr), prevSentence(nullptr) {};
    bool is_empty();
    void push(string word);
};

class List {
private:
    Sentence* firstSentence;
    Sentence* lastSentence;

public:
    List(): firstSentence(nullptr), lastSentence(nullptr) {};

    bool is_empty();
};
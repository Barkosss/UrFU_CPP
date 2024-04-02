#pragma once

#include<string>

using std::string;

struct Word {
    string word;
    Word* next;
    Word* prev;

    Word(string word): word(word), next(nullptr), prev(nullptr) {};
};

class Sentence {
private:
    Sentence* firstSentence;
    Sentence* lastSentence;

    unsigned long counterWords;
    Sentence* next;
    Sentence* prev;

public:
    Sentence(): firstSentence(nullptr), lastSentence(nullptr), counterWords(0), next(nullptr), prev(nullptr) {};

    void push(string *arrayWords, unsigned long counterWords);
    bool is_empty();
};
#pragma once

#include<string>

using std::string;

struct Word {
    string word;

    Word* firstWord;
    Word* lastWord;

    Word* next;
    Word* prev;
    
    Word(string word): word(word), firstWord(nullptr), lastWord(nullptr), next(nullptr), prev(nullptr) {};
};

class List {
private:

    struct Sentence {
        unsigned long counterWords;
        Word* firstWord;
        Word* lastWord;
        Sentence* next;
        Sentence* prev;

        Sentence(): counterWords(0), next(nullptr), prev(nullptr) {};

        void add(string *arrWords, unsigned long counterWords);
        bool is_empty();
    };
public:
    Sentence* firstSentence;
    Sentence* lastSentence;

    List(): firstSentence(nullptr), lastSentence(nullptr) {};

    void push(string *arrayWords, unsigned long counterWords);
    void print();
    bool is_empty();
};
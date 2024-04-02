#pragma once

#include<string>

class Sentence {
private:
    struct Words {
        unsigned long counter;
        std::string *words;
    };
    Sentence *next = nullptr;
    Sentence *prev = nullptr;

public:
    void push(std::string sentence);
};
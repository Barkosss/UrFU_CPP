#pragma once

#include<string>

class List {
private:
    struct Node {
        std::string word;
        unsigned long counter;
        Node* nextItem;

        Node(std::string word);
    };
    Node *first;
    Node *last;

public:
    List(): first(nullptr) {};
    bool is_empty();
    bool check(std::string word);
    void push(std::string word);
    void add(std::string word);
    void sort();
    void print(std::ofstream&writeFile);
};
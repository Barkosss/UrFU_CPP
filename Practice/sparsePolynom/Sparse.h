#pragma once

struct Node {
    long double factor;
    unsigned long long degree;

    Node *next;
    Node *prev;

    Node(): next(nullptr), prev(nullptr) {};
};

class List {
private:
    unsigned long long counter = 0;
    Node* first;
    Node* last;

public:
    List(unsigned long long counter): counter(counter) {};

    void sort();
    void push(long double factor, unsigned long long degree);
    void print();
    bool is_empty();
    List operator+(List &right);
    List operator*(List &right);
};
#pragma once

class List {
private:
    struct Node {
        int index;
        Node *next;
        Node *prev;

        Node(): index(-1), next(nullptr), prev(nullptr) {};
        Node(int index, Node* last): index(index), next(nullptr), prev(last) {};
    };
    Node *first;
    Node *last;

public:
    bool is_empty();
    bool is_one();
    void add(int index);
    void remove(int index);
    int print();
};
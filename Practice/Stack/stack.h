#pragma once
class Stack {
private:
    struct Node {
        int value;
        int maxValue;
        Node* prev;

        Node();
        Node(int value);
    };
    Node *pHead;

public:
    //~Stack();
    int getMax();
    void push(int value);
    int pop();
    int peek();
    bool is_empty();
};
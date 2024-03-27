#include<iostream>

#include "stack.h"

Stack::Node::Node(): value(0), maxValue(0), prev(nullptr) {};
Stack::Node::Node(int value): value(value), maxValue(value), prev(nullptr) {};

int Stack::getMax() {
    if (pHead) {
        return pHead->maxValue;
    } else {
        std::cout << "Stack is empty" << std::endl;
        return INT_MIN;
    }
}

bool Stack::is_empty() {
    return pHead == nullptr;
}

void Stack::push(int value) {
    std::cout << "push" << std::endl;
    Node *ptr = new Node(value);
    ptr->prev = pHead;
    pHead = ptr;

    if (pHead->prev == nullptr) {
        pHead->maxValue = value;
    } else {
        ptr->maxValue = std::max(value, pHead->maxValue);
        ptr->prev = pHead;
        pHead = ptr;
    }
}

int Stack::pop() {
    std::cout << "pop" << std::endl;
    if (pHead) {
        int num = pHead->value;
        Node *ptr = pHead;
        pHead = pHead->prev;
        delete ptr;
        return num;
    } else {
        std::cout << "Stack is empty" << std::endl;
        return INT_MIN;
    }
}

int Stack::peek() {
    return pHead->value;
}
/*
Stack::~Stack() {

}
*/
#pragma once

#include<fstream>

struct Node {
    int value;
    Node* nextValue;
    Node* nextNode;

    Node(int value): value(value), nextValue(nullptr), nextNode(nullptr) {};
    Node operator[](int index);
    std::ofstream& operator<<(std::ofstream& stream) {};
};
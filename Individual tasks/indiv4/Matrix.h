#pragma once

#include<fstream>
#include "Node.h"

class Matrix {
private:
    Node* headNode;

public:
    unsigned size;
    Matrix(std::ifstream& inFile, unsigned size): size(size), headNode(nullptr) {};
    Node operator[](int index);
};

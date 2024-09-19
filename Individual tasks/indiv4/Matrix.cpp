#include<fstream>

#include "Matrix.h"
#include "Node.h"


Matrix::Matrix(std::ifstream& inFile, unsigned size) {
    int element;

    Node* matrix = headNode;
    for(unsigned indexRow = 0; indexRow < size; indexRow++) {
        for(unsigned indexColumn = 0; indexColumn < size; indexColumn++) {
            inFile >> element;
            matrix = new Node(element);
            matrix = matrix->nextValue;
        }
        matrix = matrix->nextNode;
    }
}

Node Matrix::operator[](int index) {
    Node* ptr = this->headNode;
    while(index) {
        ptr = ptr->nextValue;
        index--;
    }

    return *ptr;
}
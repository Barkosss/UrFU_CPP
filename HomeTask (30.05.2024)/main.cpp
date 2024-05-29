#include<iostream>
#include<fstream>

#include "/media/barkos/Data/Project/barkocpp/Vector/Vector.h"

struct Node {
    unsigned long long value;

    Node* headNode;
    Node* leftNode;
    Node* rightNode;

    Node(unsigned long long value): value(value), headNode(nullptr), leftNode(nullptr), rightNode(nullptr) {};
};

class Tree {
private:
    Node* headTree;

public:
    // Constructor for the class
    Tree(): headTree(nullptr) {};

    // Add an element to the tree
    void push(unsigned long long value) {
        Node* ptr = new Node(value);
        // ...
        // ...
        // ...
    }

    // Checking that the tree is balanced
    bool isBalanced() {
        // ...
        // ...
        // ...
    }

    // Get an array with elements that are divided into their nearest descendant.
    int* getDivChild() {
        int* arrayDivChild = new int[1];

        
        
        return arrayDivChild;
    }

    // Output the tree to the console
    void print() {
        // ...
        // ...
        // ...
    }

    // Output the tree to a file
    void print(std::ofstream&writeFile) {
        // ...
        // ...
        // ...
    }
};


int main() {
    std::ifstream readFile("input.barsik");
    std::ofstream writeFile("output.barsik");

    Tree tree = Tree();
    unsigned long long value;
    while(!readFile.eof()) {
        readFile >> value;
        tree.push(value);
    }

    // Task #1
    std::cout << "Task #1: " << tree.isBalanced() << std::endl;
    std::cout << std::endl;

    // Task #2
    std::cout << "Task #2: " << std::endl;
    int* arrayDivides = tree.getDivChild();
    unsigned long long size = arrayDivides[0];
    for(unsigned long long index = 1; index < size; index++) {
        std::cout << arrayDivides[index] << " ";
    }
    std::cout << std::endl;

    // Output tree in file
    tree.print(writeFile);

    std::cout << "Program is exit" << std::endl;
    return 0;
}
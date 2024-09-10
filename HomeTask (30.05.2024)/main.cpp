#include<iostream>
#include<fstream>
#include<cmath>

#include "Vector.h"

struct Page {
    unsigned long long value;

    Page* headPage;
    Page* leftPage;
    Page* rightPage;

    Page(unsigned long long value): value(value), headPage(nullptr), leftPage(nullptr), rightPage(nullptr) {};
};

class Tree {
private:
    Page* headTree;

    // Get Divisors (Recursion)
    void getDivChildRecurs(Page* ptrPage, Vector<unsigned long long> arrayDivChild) {

        if (!ptrPage) {
            return;
        }

        // If the current element is divided by the left child
        if (ptrPage->leftPage && ptrPage->value % ptrPage->leftPage->value == 0) {
            arrayDivChild.push(ptrPage->value);
        }

        // If the current element is divided by the right child
        if (ptrPage->rightPage && ptrPage->value % ptrPage->rightPage->value == 0) {
            arrayDivChild.push(ptrPage->value);
        }
        
        // We go through the left tree
        getDivChildRecurs(ptrPage->leftPage, arrayDivChild);

        // We go through the right tree
        getDivChildRecurs(ptrPage->rightPage, arrayDivChild);
    }

    // Output a tree to a console (Recursion)
    void printRecConsole(Page* ptrPage) {
        if (ptrPage != nullptr) {
            std::cout << ptrPage->value << " ";
            this->printRecConsole(ptrPage->leftPage);
            this->printRecConsole(ptrPage->rightPage);
        }
    }

    // Output a tree to a file (Recursion)
    void printRecFile(std::ofstream&writeFile, Page* ptrPage) {
        if (ptrPage != nullptr) {
            writeFile << ptrPage->value << " ";
            this->printRecFile(writeFile, ptrPage->leftPage);
            this->printRecFile(writeFile, ptrPage->rightPage);
        }
    }

    // Calculating the height of a tree
    unsigned long long height(Page* root) {

        // Checking for an empty tree
        if (root == nullptr) {
            return 0;
        }

        // We return the maximum length of the trees + 1, to account for the current
        return std::max(height(root->leftPage), height(root->rightPage)) + 1;
    }

    // Checking that the tree is balanced through recursion
    bool isBalancedRec(Page* ptrPage) {

        // Checking for an empty tree
        if (!headTree) {
            return true;
        }

        // Checking for an empty tree
        if (!ptrPage) {
            return true;
        }

        unsigned long long leftHeight = height(ptrPage->leftPage);
        unsigned long long rightHeight = height(ptrPage->rightPage);

        // Checking for the difference between two lengths, if greater than 1, then the tree is not balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        // Check if the left and right tree are balanced
        return isBalancedRec(ptrPage->leftPage) * isBalancedRec(ptrPage->rightPage);
    }

public:
    // Constructor for the class
    Tree(): headTree(nullptr) {};

    // Add an element to the tree
    void push(unsigned long long value) {
        Page* ptr = new Page(value);

        // Checking for an empty tree
        if (!headTree) {
            headTree = ptr;
            return;
        }

        // Finding the right place to insert the element
        Page* ptr_temp = headTree;
        while(ptr_temp->leftPage || ptr_temp->rightPage) {
            // Should we add our element to the left leaf of the current vertex
            if (ptr->value < ptr_temp->value && !ptr_temp->leftPage) {
                ptr_temp->leftPage = ptr;
            }

            // Should we add our element to the right sheet of the current vertex
            else if (ptr_temp->value <= ptr->value && !ptr_temp->rightPage) {
                ptr_temp->rightPage = ptr;
            }

            // If the element is smaller than the current one, consider the left tree
            else if (ptr-value < ptr_temp) {
                ptr_temp = ptr_temp->leftPage;
            }

            // If the element is smaller than the current one, consider the right tree
            else {
                ptr_temp = ptr_temp->rightPage;
            }
        }
    }

    // Checking that the tree is balanced
    bool isBalanced() {
        // Checking that the tree is balanced through recursion
        return isBalancedRec(headTree);
    };

    // Get an array with elements that are divided into their nearest descendant.
    Vector<unsigned long long> getDivChild() {
        Vector<unsigned long long> arrayDivChild = Vector<unsigned long long>();

        getDivChildRecurs(headTree, arrayDivChild);
        
        return arrayDivChild;
    }

    // Output the tree to the console
    void print() {
        printRecConsole(this->headTree);
    }

    // Output the tree to a file
    void print(std::ofstream&writeFile) {
        printRecFile(writeFile, this->headTree);
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
    std::cout << "Task #1: " << ((tree.isBalanced()) ? ("True") : ("False")) << std::endl;
    std::cout << std::endl;

    // Task #2
    std::cout << "Task #2: ";
    Vector<unsigned long long> arrayDivides = tree.getDivChild();
    unsigned long long size = arrayDivides.size();
    if (!size) {
        std::cout << "Array is empty";
    }
    for(unsigned long long index = 1; index < size; index++) {
        std::cout << arrayDivides[index] << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;

    // Output tree in file
    //tree.print(writeFile);

    std::cout << "Program is exit" << std::endl;
    return 0;
}
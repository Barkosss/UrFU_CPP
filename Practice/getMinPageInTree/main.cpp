#include<iostream>
#include<limits.h>
#include<fstream>
//#include<Vector.h>

long long minValueOfTree = LLONG_MAX;

struct Page {
    long long value;

    Page* leftPage;
    Page* rightPage;
    Page* headPage;

    Page(long long value): value(value), headPage(nullptr), leftPage(nullptr), rightPage(nullptr) {};
};

class Tree {
private:
    unsigned long long index;
    Page* headTree;


    // Get the minimum value in the tree (Recursion)
    void getMinRec(Page* ptrPage) {
        if (ptrPage != nullptr) {
            minValueOfTree = std::min(minValueOfTree, ptrPage->value);
            this->getMinRec(ptrPage->leftPage);
            this->getMinRec(ptrPage->rightPage);
        }
    }

public:
    // Default constructor
    Tree(): index(0), headTree(nullptr) {};

    // Add an element to the tree
    void push(long long value) {
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

    // Get the minimum value in the tree
    void getMin() {
        minValueOfTree = std::min(minValueOfTree, headTree->value);
        getMinRec(headTree);
    }
};


int main() {
    std::ifstream readFile("input.barsik");

    Tree tree = Tree();
    long long value;
    while(!readFile.eof()) {
        readFile >> value;
        tree.push(value);
    }

    // Get the minimum value in the tree
    tree.getMin();

    std::cout << minValueOfTree << std::endl;
    return 0;
}
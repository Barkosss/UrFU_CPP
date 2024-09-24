#include<iostream>
#include<fstream>

/*
Проверьте, что заданное на входе бинарное дерево является сбалансированным,
т.е. для любого узла этого дерева выполняется условие,
что его высоты левого и правого поддерева отличаются не более,
чем на единицу.
*/

using std::abs;
using std::cout;
using std::endl;
using std::ifstream;

struct Node {
    unsigned long long value;
    Node* leftNode;
    Node* rightNode;

    Node(unsigned long long value): value(value), leftNode(nullptr), rightNode(nullptr) {};
};

class Tree {
private:
    Node* headTree;

    // Calculating the height of a tree
    long long height(Node* root) {

        // Checking for an empty tree
        if (root == nullptr) {
            return 0;
        }

        // We return the maximum length of the trees + 1, to account for the current
        return std::max(height(root->leftNode), height(root->rightNode)) + 1;
    }

    bool isBalancedRec(Node* ptrNode) {

        if (!headTree || !ptrNode) {
            return true;
        }

        long long leftHeight = height(ptrNode->leftNode);
        long long rightHeight = height(ptrNode->rightNode);

        // Checking for the difference between two lengths, if greater than 1, then the tree is not balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        // Check if the left and right tree are balanced
        return isBalancedRec(ptrNode->leftNode) * isBalancedRec(ptrNode->rightNode);
    };

public:
    Tree(): headTree(nullptr) {};

    // Add an element to the tree
    void push(unsigned long long value) {
        Node* ptr = new Node(value);

        // Checking for an empty tree
        if (!headTree) {
            headTree = ptr;
            return;
        }

        // Finding the right place to insert the element
        Node* ptr_temp = headTree;
        while(ptr_temp->leftNode || ptr_temp->rightNode) {
            // Should we add our element to the left leaf of the current vertex
            if (ptr->value < ptr_temp->value && !ptr_temp->leftNode) {
                ptr_temp->leftNode = ptr;
            }

                // Should we add our element to the right sheet of the current vertex
            else if (ptr_temp->value <= ptr->value && !ptr_temp->rightNode) {
                ptr_temp->rightNode = ptr;
            }

                // If the element is smaller than the current one, consider the left tree
            else if (ptr-value < ptr_temp) {
                ptr_temp->leftNode = ptr_temp;
                //ptr_temp = ptr_temp->leftNode;
            }

                // If the element is smaller than the current one, consider the right tree
            else {
                ptr_temp = ptr_temp->rightNode;
            }
        }
    }

    bool isBalance() {
        return isBalancedRec(headTree);
    }
};


int main() {
    ifstream inFile("input.txt");

    Tree tree = Tree();
    unsigned index;
    while(!inFile.eof()) {
        inFile >> index;
        tree.push(index);
    }

    cout << "Answer: " << ((tree.isBalance()) ? ("true") : ("false")) << endl;
    cout << "Program is done!" << endl;
    return 0;
}
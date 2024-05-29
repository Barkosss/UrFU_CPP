#include "Node.h"

class Grath {
private:
    Node* headNode;
    Node* tailNode;

public:
    void push(unsigned long long indexParent, unsigned long long indexChild) {
        Node* ptr = new Node;
        ptr->indexParent = indexParent;
        ptr->indexChild = indexChild;
        if (headNode == nullptr) {
            headNode = ptr;
            tailNode = ptr;
            return;
        }
        tailNode->nextNode = ptr;
        tailNode = ptr;
    }

    void print() {

    }
};
#include "Node.h"

Node Node::operator[](int index) {
    Node* ptr = this;
    while(index) {
        ptr = ptr->nextNode;
        index--;
    }

    return *ptr;
};

std::ofstream& Node::operator<<(std::ofstream& stream) {
    stream << this->value;
    return stream;
}
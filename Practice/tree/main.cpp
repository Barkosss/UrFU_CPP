#include<iostream>
#include<fstream>

std::ifstream readFile("tree.barsik");

struct Node {
    unsigned index;
    Node* left;
    Node* right;

    Node(unsigned index): index(index) {};
};

class Tree {
private:
    Node* root;

public:
    Tree(): root(nullptr) {};

    void push(unsigned index) {
        if (!root) {
            root = new Node(index);
            return;
        } else {
            // Добавление листка
            // ...
        }
    }

    unsigned getCounter() {
        unsigned counter = 0;


        return counter;        
    }
};

int main() {
    unsigned counterNodes;
    readFile >> counterNodes;

    unsigned index;
    Tree tree = Tree();
    for(unsigned indexNode = 0; indexNode < counterNodes; indexNode++) {
        readFile >> index;
        tree.push(index);
    }

    std::cout << tree.getCounter() << std::endl;
    return 0;
}
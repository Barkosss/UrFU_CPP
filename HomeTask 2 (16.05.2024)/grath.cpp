#include<iostream>
#include<fstream>

std::ifstream readFile("grath.barsik");
std::ofstream writeFile("output.barsik");

class Grath {
private:
    struct Edge {
        unsigned long long indexEdge;
        Edge* nextEdge;

        Edge(unsigned long long indexEdge): indexEdge(indexEdge) {};
        Edge(): nextEdge(nullptr) {};
    };

    struct Node {
        unsigned long long indexNode;
        Edge* ptrEdge;

        Node* nextNode;

        Node(unsigned long long indexNode): indexNode(indexNode) {};
    };

    Node* ptrHead;
    Node* ptrTail;

public:
    // Добавить
    void push(unsigned long long indexNode, unsigned long long counterEdge) {
        // Создание главное вершины
        Node* ptr = new Node(indexNode);

        if (ptrHead == nullptr) {
            ptrHead = ptr;
            ptrTail = ptr;
        } else {
            ptrTail->nextNode = ptr;
            ptrTail = ptr;
        }

        // Добавление смежных вершин к главной вершине
        unsigned long long edge;
        readFile >> edge;
        Edge* ptrEdge = new Edge();

        if (edge > indexNode) {
            ptr->ptrEdge = ptrEdge;
        }

        for(unsigned long long indexEdge = 1; indexEdge < counterEdge; indexEdge++) {
            readFile >> edge;
            if (edge < indexEdge) {
                continue;
            }

            Edge* ptrNextEdge = new Edge(edge);
            ptrEdge->nextEdge = ptrNextEdge;
            ptrEdge = ptrNextEdge;
        }
    }

    // Вывести
    void print() {

    }
};

int main() {
    // Counter node | Counter Edge | Index top node
    unsigned long long counterNode, counterEdge, indexTopNode;
    readFile >> counterNode;

    Grath grath = Grath();
    for(unsigned long long indexNode = 0; indexNode < counterNode; indexNode++) {
        readFile >> counterEdge;
        readFile >> indexTopNode;
        
        grath.push(indexTopNode, counterEdge);
    }


    return 0;
};
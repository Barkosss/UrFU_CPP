#pragma once


// Класс для графов
class Grath {
private:

    // Структура для вершин графа
    struct Node {
        unsigned long long indexNode;
        unsigned long long parent;

        Node* nextNode;
        Node* prevNode;

        Node(unsigned long long parent, unsigned long long indexNode): parent(parent), indexNode(indexNode) {};
    };

    // Структура для рёбер графа
    struct Edge {
        Node* nodeFrom;
        Node* nodeTo;
        unsigned long long length;

        Edge(): nodeFrom(nullptr), nodeTo(nullptr) {};
        Edge(unsigned long long length): length(length) {};
        Edge(Node* nodeFrom, Node* nodeTo, unsigned long long length): nodeFrom(nodeFrom), nodeTo(nodeTo), length(length) {};
    };

    Edge* pEdgeHead;
    Node* pGrathHead;

public:
    // Добавить ребро в список
    void push_edge();
    // Добавить вершину в граф
    void push_node(unsigned long long parent, unsigned long long indexNode);
    // Вывести рёбра
    void dump_edge();
    // Вывести граф
    void dump_node();
    // Получить длину изолированных вершин графа
    unsigned long long getLengthIsolated();
};
#include<iostream>
#include<fstream>
#include<string>

#include "/media/barkos/Data/Visual Studio Code/C++/Vector/vector.h"
#include "Grath.h"

/* ФОРМАТ ХРАНЕНИЯ ДАННЫХ  В ФАЙЛЕ
i a0 a1 a2 a3 a4

i - Индекс вершины
{a} - Индексы вершин, к которым соединена i-ая вершина

*/

// Получить максимальное значение
unsigned long long max(unsigned long long left, unsigned long long right) {
    if (left < right) {
        return right;
    }
    return left;
}

// Получить минимальное значение
unsigned long long min(unsigned long long left, unsigned long long right) {
    if (left > right) {
        return right;
    }
    return left;
}


int main() {
    std::ifstream readFile("grath.barsik");
    // Граф
    Grath grath = Grath();

    // Количество всего вершин
    unsigned long long counterNodes;
    // Количество вершин у текущей вершины | Индекс Вершины
    unsigned long long counterNodesCurrentNode, node;
    readFile >> counterNodes;

    for(unsigned long long indexNode = 0; indexNode < counterNodes; indexNode++) {
        readFile >> counterNodesCurrentNode;

        for(unsigned long long indexCurrentNode = 0; indexCurrentNode < counterNodesCurrentNode; indexCurrentNode++) {
            readFile >> node;

            
        }
    }

    return 0;
}



/*
int main() {
    std::ifstream readFile("grath.barsik");

    // Граф с вершинами
    Grath grath = Grath();
    // Количество всего вершин, к которым что-то привязано
    unsigned long long counterNode, counterCurrentNode;
    readFile >> counterNode;

    // Индекс текущей вершины
    std::string row;
    unsigned long long indexCurrentNode;
    for(unsigned long long index = 0; index < counterNode; index++) {
        // Чтение строки с информацией
        getline(readFile, row);
    }


    // Список рёбер
    Edge edge = Edge();

    return 0;
}
*/
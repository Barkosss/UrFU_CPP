#include<iostream>
#include<fstream>
#include<string>

#include "searchWidth.h"

/*
Указания по выполнению ИДЗ No4: 
- Необходимые структуры данных разместить в отдельном заголовочном файле. 
- Реализовать алгоритм (написать функцию) в отдельном cpp-файле. 
- Тест (главная программная единица main), демонстрирующий работу алгоритма, 
также разместить в отдельном cpp-файле. 
- Рекурсию не использовать.


ЗАДАЧА:
В начале исходного файла задано n - число вершин графа и далее его 
матрица смежности. Поиском в ширину найти все компоненты 
связности графа.
*/

std::ifstream readFile("input.barsik");
std::ofstream writeFile("output.barsik");

int main() {
    // Число вершин графа
    unsigned counterNodes;
    readFile >> counterNodes;

    bool connection;
    Grath grath = Grath();

    // indexRow - Родитель
    // indexCollunm - Ребёнок
    for(unsigned indexRow = 0; indexRow < counterNodes; indexRow++) {
        for(unsigned indexCollumn = 0; indexCollumn < counterNodes; indexCollumn++) {
            readFile >> connection;
            // Если есть связь --> Добавляем в граф
            if (connection && indexRow < indexCollumn) {
                grath.push(indexRow, indexCollumn);
            }
        }
    }

    searchWidth(grath);

    return 0;
}
#include<iostream>
#include<fstream>

#include "Matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

/*
В начале исходного файла задано n - число вершин графа и далее его
матрица смежности. Поиском в ширину найти все компоненты
связности графа.
 */

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    unsigned countRowAndColumn;
    inFile >> countRowAndColumn;

    Matrix matrix = Matrix(inFile, countRowAndColumn);
    cout << matrix[0][0].value;

    return 0;
}
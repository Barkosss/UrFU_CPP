#include<iostream>
#include<fstream>

#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int main() {
    
    ifstream readFile("matrixs.txt");
    ofstream writeFile("result.txt");

    // Проверка на возможность открыть файл для чтения
    if (!readFile.is_open()) {
        cout << "Error: Open file";
        return 1;
    }

    if (readFile.peek() == EOF) {
        cout << "The file is empty" << endl;
        return 2;
    }

    long counterMatrix;
    readFile >> counterMatrix;

    for(int indexMatrix = 0; indexMatrix < counterMatrix; indexMatrix++) {
        // Чтение матрицы из файла
        ReadMatrix(readFile, writeFile);
    }

    cout << "Complete!" << endl;

    return 0;
}
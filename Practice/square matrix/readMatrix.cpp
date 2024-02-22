#include<iostream>
#include<fstream>

#include "matrix.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

void ReadMatrix(ifstream&readFile, ofstream&writeFile) {
    int sizeOfMatrix;
    readFile >> sizeOfMatrix;

    long double **matrix = new long double*[sizeOfMatrix];

    // Чтение матрицы
    for(int rows = 0; rows < sizeOfMatrix; rows++) {
        matrix[rows] = new long double[sizeOfMatrix];
        for(int collumns = 0; collumns < sizeOfMatrix; collumns++) {
            readFile >> matrix[rows][collumns];
        }
    }

    cout << "Read files completed!" << endl;

    // Сглаживание матрицы
    SmoothingMatrix(sizeOfMatrix, matrix, writeFile);

    // Удаление матрицы
    /*
    for(int rows = 0; rows < sizeOfMatrix; rows++) {
        delete[] matrix[rows];
    }
    delete[] matrix;
    */
}
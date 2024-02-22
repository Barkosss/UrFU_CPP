#include<iostream>
#include<fstream>

#include"matrix.h"

using std::ofstream;

void SmoothingMatrix(long sizeOfMatrix, long double **matrix, ofstream&writeFile) {

    // Создание новой матрицы
    long double **smoothingMatrix = new long double*[sizeOfMatrix];
    for(int rows = 0; rows < sizeOfMatrix; rows++) {
        smoothingMatrix[rows] = new long double[sizeOfMatrix];
        for(int collumns = 0; collumns < sizeOfMatrix; collumns++) {
            smoothingMatrix[rows][collumns] = 0;
        }
    }

    // Сглаживание (index - строка | jndex - столбец)
    int counterNeighbours = 0;
    long double sumNeighbours = 0;
    for(int index = 0; index < sizeOfMatrix; index++) {
        for(int jndex = 0; jndex < sizeOfMatrix; jndex++) {
            // Реализовать сглаживание...
            if (index - 1 > 0) {
                counterNeighbours++;
                sumNeighbours += matrix[index-1][jndex];
            }

            if (index + 1 < sizeOfMatrix) {
                counterNeighbours++;
                sumNeighbours += matrix[index + 1][jndex];
            }

            if (jndex - 1 > 0) {
                counterNeighbours++;
                sumNeighbours += matrix[index][jndex - 1];
            }

            if (jndex + 1 < sizeOfMatrix) {
                counterNeighbours++;
                sumNeighbours += matrix[index][jndex + 1];
            }

            smoothingMatrix[index][jndex] = sumNeighbours / counterNeighbours;

            // Обнуляем счётчик и сумму
            counterNeighbours = 0;
            sumNeighbours = 0;
        }
    }

    long double sumMainDiagonal = 0;
    // Сумма
    for(int index = 0; index < sizeOfMatrix; index++) {
        for(int jndex = 0; jndex < index; jndex++) {
            sumMainDiagonal += std::abs(smoothingMatrix[index][jndex]);
        }
    }

    // Запись новой матрицы
    WriteMatrix(sizeOfMatrix, smoothingMatrix, sumMainDiagonal, writeFile);
}
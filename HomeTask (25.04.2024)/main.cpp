#include<iostream>
#include<fstream>

#include "Queue.h"
#include "Matrix.h"


// Задание #1: Матрица
void SystemMatrix(std::ifstream& readFile) {
    unsigned long long counter;
    readFile >> counter;

    for(unsigned long indexOperation = 0; indexOperation < counter; indexOperation++) {
        char operation;
        readFile >> operation;

        // Сложение
        if (operation == '+') {
            unsigned long long length;
            readFile >> length;
            
            // Первая матрица
            Matrix oneMatrix = Matrix(length);
            long long** arrayMatrix = new long long*[length];
            for(unsigned index = 0; index < length; index++) {
                arrayMatrix[index] = new long long[length];
                for(unsigned jndex = 0; jndex < length; jndex++) {
                    readFile >> arrayMatrix[index][jndex];
                }
            }
            oneMatrix.setArray(arrayMatrix);

            // Вторая матрица
            Matrix twoMatrix = Matrix(length);
            for(unsigned index = 0; index < length; index++) {
                for(unsigned jndex = 0; jndex < length; jndex++) {
                    readFile >> arrayMatrix[index][jndex];
                }
            }
            twoMatrix.setArray(arrayMatrix);

            Matrix resultMatrix = oneMatrix + twoMatrix;

            std::cout << "Result sum: " << std::endl << resultMatrix << std::endl;
        }

        // Вычитание
        else if (operation == '-') {
            unsigned long long length;
            readFile >> length;

            // Первая матрица
            Matrix oneMatrix = Matrix(length);
            long long** arrayMatrix = new long long*[length];
            for(unsigned index = 0; index < length; index++) {
                arrayMatrix[index] = new long long[length];
                for(unsigned jndex = 0; jndex < length; jndex++) {
                    readFile >> arrayMatrix[index][jndex];
                }
            }
            oneMatrix.setArray(arrayMatrix);

            // Вторая матрица
            Matrix twoMatrix = Matrix(length);
            for(unsigned index = 0; index < length; index++) {
                for(unsigned jndex = 0; jndex < length; jndex++) {
                    readFile >> arrayMatrix[index][jndex];
                }
            }
            twoMatrix.setArray(arrayMatrix);

            Matrix resultMatrix = oneMatrix - twoMatrix;

            std::cout << "Result sub: " << std::endl << resultMatrix << std::endl;
        }

        // Умножение на матрицу или на скаляр
        else if (operation == '*') {
            char what;
            readFile >> what;

            unsigned long long length;
            readFile >> length;

            // Первая матрица
            Matrix oneMatrix = Matrix(length);
            long long** arrayMatrix = new long long*[length];
            for(unsigned index = 0; index < length; index++) {
                arrayMatrix[index] = new long long[length];
                for(unsigned jndex = 0; jndex < length; jndex++) {
                    readFile >> arrayMatrix[index][jndex];
                }
            }
            oneMatrix.setArray(arrayMatrix);

            // Если умножение на скаляр
            if (what == 's') {
                long long scalar;
                readFile >> scalar;

                Matrix resultMulti = oneMatrix * scalar;
                std::cout << "Result multi by scalar: " << std::endl << resultMulti << std::endl;
            } 
            
            // Если умножение на матрицу
            else {
                // Вторая матрица
                Matrix twoMatrix = Matrix(length);
                for(unsigned index = 0; index < length; index++) {
                    for(unsigned jndex = 0; jndex < length; jndex++) {
                        readFile >> arrayMatrix[index][jndex];
                    }
                }
                twoMatrix.setArray(arrayMatrix);

                Matrix resultMulti = oneMatrix * twoMatrix;
                std::cout << "Result multi by matrix: " << std::endl << resultMulti << std::endl;
            }
        }
    }
}

// Задание #2: Стэк
void SystemQueue(std::ifstream& readFile) {
    // ...    
}


int main() {
    // Задание #1: Матрица
    std::ifstream readFileMatrix("matrix.barsik");
    SystemMatrix(readFileMatrix);
    readFileMatrix.close();
    

    // Задание #2: Стэк
    std::ifstream readFileStack("stack.barsik");
    SystemQueue(readFileStack);
    readFileStack.close();

    return 0;
}
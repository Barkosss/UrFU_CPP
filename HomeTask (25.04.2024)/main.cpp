#include<iostream>
#include<fstream>

#include "Queue.h"
#include "Matrix.h"


// Задание #1: Матрица
void SystemMatrix(std::ifstream& readFile) {
    std::ofstream writeFile("output.barsik");
    long long value; long double scalar;
    unsigned long long counterOperation, counterElements, indexCollumn, indexRow;
    char _char;
    readFile >> counterOperation >> _char;

    for(unsigned long long indexOperation = 0; indexOperation < counterOperation; indexOperation++) {
        Matrix matrix;
        
        // Сложение
        if (_char == '+') {
            Matrix oneMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                oneMatrix.push(value, indexCollumn, indexRow);
            }

            Matrix twoMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                twoMatrix.push(value, indexCollumn, indexRow);
            }

            matrix = oneMatrix + twoMatrix;
        }

        // Разность
        else if (_char == '-') {
            Matrix oneMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                oneMatrix.push(value, indexCollumn, indexRow);
            }

            Matrix twoMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                twoMatrix.push(value, indexCollumn, indexRow);
            }

            matrix = oneMatrix - twoMatrix;
        }

        // Произведение на матрицу
        else if (_char == '*') {
            Matrix oneMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                oneMatrix.push(value, indexCollumn, indexRow);
            }

            Matrix twoMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                twoMatrix.push(value, indexCollumn, indexRow);
            }

            matrix = oneMatrix * twoMatrix;
        }

        // Произведение на скаляр
        else if (_char == 's') {
            Matrix oneMatrix = Matrix();
            readFile >> counterElements;

            for(unsigned long long indexElements = 0; indexElements < counterElements; indexElements++) {
                readFile >> indexCollumn >> indexRow >> value;
                oneMatrix.push(value, indexCollumn, indexRow);
            }

            readFile >> scalar;

            matrix = oneMatrix * scalar;
        }

        matrix.print(writeFile);
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
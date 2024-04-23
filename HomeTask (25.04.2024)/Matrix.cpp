#include<iostream>

#include "Matrix.h"

class Matrix {
private:
    unsigned long long length;
    long long **array;

public:
    // Получить размер матрицы
    unsigned long long getLength() {
        return length;
    }

    // Получить значение по индексу
    long long getValue(unsigned long long index, unsigned long long jndex) {
        return array[index][jndex];
    }

    // Присвоить значения
    long long **setArray(long long **array) {
        array = array;
    }

    // Конструктор создания
    Matrix(unsigned long long createLength) {
        length = createLength;
        array = new long long*[createLength];
        for(int index = 0; index < length; index++) {
            for(int jndex = 0; jndex < length; jndex++) {
                array[index][jndex] = 0;
            }
        }
    };

    // Конструктор копирования
    Matrix(unsigned long long copyLength, long long **copyArray) {
        length = copyLength;
        array = copyArray;
    };

    // Сложение
    Matrix operator+(Matrix &right) {
        Matrix newMatrix = Matrix(right.length);

        for(int index = 0; index < right.length; index++) {
            for(int jndex = 0; jndex < right.length; jndex++) {
                newMatrix.array[index][jndex] = this->array[index][jndex] + right.array[index][jndex];
            }
        }

        return newMatrix;
    };

    // Разность
    Matrix operator-(Matrix &right) {
        Matrix newMatrix = Matrix(right.length);

        for(int index = 0; index < right.length; index++) {
            for(int jndex = 0; jndex < right.length; jndex++) {
                newMatrix.array[index][jndex] = this->array[index][jndex] - right.array[index][jndex];
            }
        }

        return newMatrix;
    };

    // Умножение матриц
    Matrix operator *(Matrix &right) {
        Matrix newMatrix = Matrix(right.length);
        unsigned long long indexMatrix = 0;
        for(int index = 0; index < right.length; index++) {
            for(int jndex = 0; jndex < right.length; jndex++) {
                newMatrix = this->array[index][jndex] * right.array[jndex][index];
            }
        }

        return newMatrix;
    };

    // Умножение на скаляр
    Matrix operator *(long long scalar) {
        Matrix newMatrix = Matrix(this->length);

        for(int index = 0; index < length; index++) {
            for(int jndex = 0; jndex < length; jndex++) {
                newMatrix.array[index][jndex] *= scalar;
            }
        }

        return newMatrix;
    };
};

// Вывод матрицы
std::ostream& operator<<(std::ostream& ostream, Matrix& right) {
    unsigned long long lengthMatrix = right.getLength();
    for(int index = 0; index < lengthMatrix; index++) {
        for(int jndex = 0; jndex < lengthMatrix; jndex++) {
            ostream << right.getValue(index, jndex);
        }
        ostream << std::endl;
    }

    return ostream;
};
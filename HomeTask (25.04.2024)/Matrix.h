#pragma once

class Matrix {
public:// Получить размер матрицы
    unsigned long long getLength();

    // Получить значение по индексу
    long long getValue(unsigned long long index, unsigned long long jndex);

    // Присвоить значения
    long long **setArray(long long **array);

    // Конструктор создания
    Matrix(unsigned long long createLength);

    // Конструктор копирования
    Matrix(unsigned long long copyLength, long long **copyArray);

    // Сложение
    Matrix operator+(Matrix &right);

    // Разность
    Matrix operator-(Matrix &right);

    // Умножение матриц
    Matrix operator *(Matrix &right);

    // Умножение на скаляр
    Matrix operator *(long long scalar);
};

// Вывод матрицы
std::ostream& operator<<(std::ostream& os, Matrix& right);
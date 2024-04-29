#pragma once

#include<iostream>
#include<limits.h>

struct Node {
    long long value;

    unsigned long long indexCollumn;
    unsigned long long indexRow;

    Node* nextValue;

    Node(): value(0), indexCollumn(0), indexRow(0), nextValue(nullptr) {};
    Node(long long value, unsigned long long collumn, unsigned long long row): value(value), indexCollumn(collumn), indexRow(row), nextValue(nullptr) {};
};

class Matrix {
private:
    Node* first;
    Node* last;
    

public:
    Matrix(): first(nullptr), last(nullptr) {};

    bool is_empty();
    Node* check(unsigned long long indexCollumn, unsigned long long indexRow);
    long long getValue(unsigned long long indexCollumn, unsigned long long indexRow);
    void push(long long value, unsigned long long collumn, unsigned long long row);
    void sort();
    void print(std::ofstream& writeFile);

    Matrix operator+(Matrix& right);
    Matrix operator-(Matrix& right);
    Matrix operator*(Matrix& right);
    Matrix operator*(unsigned long long scalar);
};


/*
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
*/
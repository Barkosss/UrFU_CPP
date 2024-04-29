#include<iostream>
#include<fstream>

#include "Matrix.h"

// Проверка на пустоту
bool Matrix::is_empty() {
    return first;
}

// Проверить, есть ли элемент с указанными индексами
Node* Matrix::check(unsigned long long indexCollumn, unsigned long long indexRow) {
    Node* ptr = first;
    while(ptr) {
        if (ptr->indexCollumn == indexCollumn && ptr->indexRow == indexRow) {
            return ptr;
        }
    }
    return ptr;
}

// Получить элемент по индексу
long long Matrix::getValue(unsigned long long indexCollumn, unsigned long long indexRow) {
    Node* ptr = first;

    while(ptr) {
        if (ptr->indexCollumn == indexCollumn && ptr->indexRow == indexRow) {
            return ptr->value;
        }
    }
    return 0;
};


// Добавление элементов в матрицу
void Matrix::push(long long value, unsigned long long collumn, unsigned long long row) {
    Node* ptr = new Node(value, collumn, row);
    if (is_empty()) {
        first = ptr;
        last = ptr;
        return;
    }

    last->nextValue = ptr;
    last = ptr;
}

// Сортировка - Вставками
void Matrix::sort() {
    
}

/*
// function to sort a singly linked list using insertion
// sort
void sort(Node* headref) {
    // Initialize sorted linked list
    sorted = NULL;
    Node* current = headref;
    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Node* next = current->next;
        // insert current in sorted linked list
        sortedInsert(current);
        // Update current
        current = next;
    }
    // Update head_ref to point to sorted linked list
    head = sorted;
}

/*
    * function to insert a new_node in a list. Note that
    * this function expects a pointer to head_ref as this
    * can modify the head of the input linked list
    * (similar to push())
    *
void sortedInsert(Node* newnode)
{
    /* Special case for the head end
    if (sorted == NULL || sorted->val >= newnode->val) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        Node* current = sorted;
        /* Locate the node before the point of insertion
            
        while (current->next != NULL
                && current->next->val < newnode->val) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}
*/

// Сложение матриц
Matrix Matrix::operator+(Matrix& right) {
    Matrix matrixSum = Matrix();

    Node* oneMatrix = first;
    // Заполнение первой матрицей
    while(oneMatrix) {
        matrixSum.push(oneMatrix->indexCollumn, oneMatrix->indexRow, oneMatrix->value);
        oneMatrix = oneMatrix->nextValue;
    }

    Node* twoMatrix = right.first;
    // Добавление второй матрицы
    while(twoMatrix) {
        Node* findPtr = matrixSum.first;
        // Ищем элемент с нужными индексами
        while(findPtr) {
            // Еси мы нашли элемент с нужными нам индексами
            if (findPtr->indexCollumn == twoMatrix->indexCollumn && findPtr->indexRow == twoMatrix->indexRow) {
                findPtr->value = findPtr->value + twoMatrix->value;
                break;
            }
            findPtr = findPtr->nextValue;
        }

        // Если мы не нашли элемент в списке
        if (!findPtr) {
            matrixSum.push(twoMatrix->indexCollumn, twoMatrix->indexRow, twoMatrix->value);
        }
    }

    return matrixSum;
}


// Вычитание матриц
Matrix Matrix::operator-(Matrix& right) {
    Matrix matrixDiff = Matrix();

    Node* oneMatrix = first;
    // Заполнение первой матрицей
    while(oneMatrix) {
        matrixDiff.push(oneMatrix->indexCollumn, oneMatrix->indexRow, oneMatrix->value);
        oneMatrix = oneMatrix->nextValue;
    }

    Node* twoMatrix = right.first;
    // Добавление второй матрицы
    while(twoMatrix) {
        Node* findPtr = matrixDiff.first;
        // Ищем элемент с нужными индексами
        while(findPtr) {
            // Еси мы нашли элемент с нужными нам индексами
            if (findPtr->indexCollumn == twoMatrix->indexCollumn && findPtr->indexRow == twoMatrix->indexRow) {
                findPtr->value = findPtr->value - twoMatrix->value;
                break;
            }
            findPtr = findPtr->nextValue;
        }

        // Если мы не нашли элемент в списке
        if (!findPtr) {
            matrixDiff.push(twoMatrix->indexCollumn, twoMatrix->indexRow, twoMatrix->value);
        }
    }

    return matrixDiff;
}

// Произведение матрицы на матрицу
Matrix Matrix::operator*(Matrix&right) {
    Matrix matrixMulti = Matrix();



    return matrixMulti;
}

// Произведение матрицы на скаляр
Matrix Matrix::operator*(unsigned long long scalar) {
    Matrix matrixScalar = Matrix();

    Node* ptr = first;
    // Заполнение первой матрицей
    while(ptr) {
        matrixScalar.push(ptr->indexCollumn, ptr->indexRow, ptr->value * scalar);
        ptr = ptr->nextValue;
    }

    return matrixScalar;
};

void Matrix::print(std::ofstream& writeFile) {
    unsigned long long index = 1;
    Node* ptr = first;
    while(ptr) {
        writeFile << "#" << index++ << " | (" << ptr->indexCollumn << ", " << ptr->indexRow << ") = " << ptr->value << std::endl;
        ptr = ptr->nextValue;
    }
}
/*
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
};*/
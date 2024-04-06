#include<iostream>
#include<fstream>

#include "Sparse.h"

// Проверка на пустоту
bool List::is_empty() {
    return first == nullptr;
}

// Сортировка списка
void List::sort() {
    Node *ptrFirst = this->first;
    Node *ptrSecond;

    long double tempFactor;
    unsigned long long tempDegree;

    while(ptrFirst != nullptr) {
        ptrSecond = ptrFirst->next;
        while(ptrSecond != nullptr) {
            if (ptrFirst->factor < ptrSecond->factor) {
                tempFactor = ptrFirst->factor;
                tempDegree = ptrFirst->degree;
                
                ptrFirst->factor = ptrSecond->factor;
                ptrFirst->degree = ptrSecond->degree;

                ptrSecond->factor = tempFactor;
                ptrSecond->degree = tempDegree;
            }

            ptrSecond = ptrSecond->next;
        }
        ptrFirst = ptrFirst->next;
    }
}

// Добавить в список элемент
void List::push(long double factor, unsigned long long degree) {
    Node* ptr = new Node();

    ptr->factor = factor;
    ptr->degree = degree;

    if (is_empty()) {
        first = ptr;
        last = ptr;
    }
    last->next = ptr;
    ptr->prev = last;
    last = ptr;
}

void List::print() {
    std::ofstream writeFile("result.txt");

    Node* node = this->first;
    while(node) {
        writeFile << ((node->factor >= 0) ? (" + ") : (" - ")) << abs(node->factor) << "x^(" << node->degree << ")";
        node = node->next;
    }

    writeFile.close();
    std::cout << "Write is finish" << std::endl;
}

// Сложение полиномов
List List::operator+(List &right) {
    List result = List(this->counter);

    Node* node = this->first;
    while(node) {
        Node* ptr = new Node();

        ptr->factor = node->factor;
        ptr->degree = node->degree;

        if (is_empty()) {
            result.first = ptr;
            result.last = ptr;
        }
        result.last->next = ptr;
        ptr->prev = result.last;
        result.last = ptr;

        node = node->next;
    }

    long double factor;
    Node* first = this->first;
    Node* second;
    while(first) {
        second = right.first;
        while(second) {
            Node* ptr = new Node();
            factor = first->factor + second->factor;

            ptr->factor = factor;
            ptr->degree = first->degree;

            if (is_empty()) {
                first = ptr;
                last = ptr;
            }
            last->next = ptr;
            ptr->prev = last;
            last = ptr;

            second = second->next;
        }
        first = first->next;
    }

    result.sort();
    return result;
}

// Произведение полиномов
List List::operator*(List &right) {
    List result = List(this->counter * right.counter);

    long double factor;
    unsigned long long degree;

    Node* first = this->first;
    Node* second;

    while(first) {
        second = right.first;
        while(second) {
            Node* ptr = new Node();

            factor = first->factor * second->factor;
            degree = first->degree + second->degree;

            ptr->factor = factor;
            ptr->degree = degree;

            if (is_empty()) {
                first = ptr;
                last = ptr;
            }
            last->next = ptr;
            ptr->prev = last;
            last = ptr;

            second = second->next;
        }
        first = first->next;
    }

    result.sort();
    return result;
}
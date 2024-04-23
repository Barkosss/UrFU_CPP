#include<iostream>
#include<fstream>
#include<string>

#include "Queue.h"

/*
Возьмем два стека: s1 и s2.
Операцию push будем всегда делать в стек s1.

Операция pop будет устроена так:
Eсли стек s2 пустой:
    Перекладываем все элементы из s1 в s2 последовательными вызовами pop и push.
    Теперь в стеке s2 лежат элементы в обратном порядке
    (самый верхний элемент — это самый первый положенный элемент в нашу очередь).
Если s2 не пуст:
    Тупо достаем элементы из него.
Как только s2 окажется снова пустым повторяем ту же операцию.
*/

struct Stack {
    int intValue;

    Stack* nextStack;

    Stack(int value): intValue(value), nextStack(nullptr) {};
};

class Queue {
private:
    Stack* oneStackFirst;
    Stack* oneStackLast;

    Stack* twoStackFirst;
    Stack* twoStackLast;
    
public:
    bool is_empty(Stack* stack) {
        return stack == nullptr;
    }

    void push(int value) {
        Stack* ptrStack = new Stack(value);

        if (is_empty(oneStackFirst)) {
            oneStackFirst = ptrStack;
            oneStackLast = ptrStack;
        }

        oneStackLast->nextStack = ptrStack;
        oneStackLast = ptrStack;
    }

    void pop() {

        
    }
};
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


Stack::Stack(int value): intValue(value) {};

int Stack::getValue() {
    return intValue;
}

void Stack::push(int value) {
    // ...
}

int Stack::pop() {
    int output = intValue;

    // ...

    return output;
}

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
        // ...
    }

    /*
    def pop(self):
        if not self.s2:
            while self.s1:
                self.s2.push(self.s1.pop())
        return self.s2.pop()
    */
    int pop() {
        // ...
    }
};



/*
struct Stack {
    int intValue;

    Stack* nextStack;
    Stack* prevStack;

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

        ptrStack->prevStack = oneStackLast;
        oneStackLast->nextStack = ptrStack;
        oneStackLast = ptrStack;
    }

    int popStack(Stack* ptrStack) {
        int value = ptrStack->intValue;
        
        return value;
    }

    /*
    def pop(self):
        if not self.s2:
            while self.s1:
                self.s2.push(self.s1.pop())
        return self.s2.pop()
    */
   /*
    int pop() {
        if (!is_empty(twoStackFirst)) {
            Stack *ptrStack = oneStackLast;
            while(ptrStack) {
                
            }
        }

        return 0;
    }
};


class Queue:
    def __init__(self):
        self.s1 = Stack()
        self.s2 = Stack()

    def push(self, elem):
        self.s1.push(elem)

    def pop(self):
        if not self.s2:
            while self.s1:
                self.s2.push(self.s1.pop())
        return self.s2.pop()

    def get_min(self):
        return min(self.s1.get_min(), self.s2.get_min())
*/
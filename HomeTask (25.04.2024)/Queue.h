#pragma once

struct Stack {
    int intValue;

    Stack* nextStack;
    Stack* prevStack;

    Stack(int value): intValue(value) {};

    int getValue() {
        return intValue;
    }

    void push(int value) {
        // ...
    }

    int pop() {
        int output = intValue;

        // ...

        return output;
    }
};

class Queue {
    // Пустой ли список
    bool is_empty(Stack* stack);

    // Добавить число в стэк
    void push(int value);

    // Удалить элемент из стэка
    void pop();
};
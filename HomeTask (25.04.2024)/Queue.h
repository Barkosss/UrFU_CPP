#pragma once

class Queue {
    // Пустой ли список
    bool is_empty();

    // Добавить число в стэк
    void push(long long value);

    // Удалить элемент из стэка
    void pop();

    // Очистить стэк
    void clear();
};
#include "List.h"

// Проверить, что остался один элемент в списке
bool List::is_one() {
    return (this->first->next == nullptr) && (this->first->prev == nullptr);
}

// Проверка, пустой ли список
bool List::is_empty() {
    return first == nullptr;
}

// Добавить
void List::add(int index) {
    Node *ptr = new Node(index, last);
    ptr->next = first->next;

    if (is_empty()) {

        first = ptr;
        last = ptr;
        return;
    }

    last = ptr;
    return;
}

// Удалить
void List::remove(int index) {
    Node *ptr;
    while(ptr->index != index) {
        ptr = ptr->next;
    }

    Node *tempPtr = ptr;
    ptr->prev->next = tempPtr->next;
    tempPtr->next->prev = tempPtr->prev;
}

// Вывести
int List::print() {
    return this->first->next->index;
}
#include<iostream>
#include<fstream>
#include<string>

#include "List.h"

using std::string;


List::Node::Node(string word): word(word), counter(0), nextItem(nullptr) {};

bool List::is_empty() {
    return first == nullptr;
}

void List::push(string word) {
    Node* ptr = new Node(word);
    if (is_empty()) {
        first = ptr;
        last = ptr;
        return;
    }
    last->nextItem = ptr;
    last = ptr;
};

void List::add(string word) {
    Node *ptr = first;
    while(ptr) {
        if (ptr->word == word) {
            ptr->counter++;
        }
        ptr = ptr->nextItem;
    }
};

bool List::check(string word) {
    Node *ptr = first;
    while(ptr) {
        if (ptr->word == word) {
            return true;
        }
        ptr = ptr->nextItem;
    }
    return false;
}

void List::sort() {
    Node *ptrFirst = first;
    Node *ptrSecond;

    // std::string word;
    // unsigned long counter;

    std::string tempWord;
    unsigned long tempCounter;
    while(ptrFirst != nullptr) {
        ptrSecond = ptrFirst->nextItem;
        while(ptrSecond != nullptr) {
            if (ptrFirst->counter < ptrSecond->counter) {
                tempWord = ptrFirst->word;
                tempCounter = ptrFirst->counter;
                
                ptrFirst->word = ptrSecond->word;
                ptrFirst->counter = ptrSecond->counter;

                ptrSecond->word = tempWord;
                ptrSecond->counter = tempCounter;
            }

            ptrSecond = ptrSecond->nextItem;
        }
        ptrFirst = ptrFirst->nextItem;
    }
};

void List::print(std::ofstream&writeFile) {
    if (is_empty()) return;
    Node* ptr = first;
    while (ptr) {
        writeFile << ptr->word << ": " << ptr->counter << std::endl;
        ptr = ptr->nextItem;
    }
    writeFile << std::endl;
};

/*
class List {
private:
    Node *first;
    Node *last;

    List(): first(nullptr) {};

public:
    bool is_empty() {
        return first == nullptr;
    }
    
    void push(string word) {
        Node* p = new Node(word);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->nextItem = p;
        last = p;
    };

    void add(string word) {
        Node *ptr = first;
        while(ptr) {
            if (ptr->word == word) {
                ptr->counter++;
            }
            ptr = ptr->nextItem;
        }
    }

    bool check(string word) {
        Node *ptr = first;
        while(ptr) {
            if (ptr->word == word) {
                return true;
            }
            ptr = ptr->nextItem;
        }
        return false;
    }

    void sort() {
        Node *ptrFirst = first;
        Node *ptrSecond;

        Node *temp;
        while(ptrFirst->nextItem != nullptr) {
            ptrSecond = ptrFirst->nextItem;
            while(ptrSecond->nextItem != nullptr) {
                if (ptrFirst->counter < ptrSecond->counter) {
                    temp = ptrFirst;
                    ptrFirst = ptrSecond;
                    ptrSecond = temp;
                }

                ptrSecond = ptrSecond->nextItem;
            }
            ptrFirst = ptrFirst->nextItem;
        }        
    };

    void print(std::ofstream&writeFile) {
        if (is_empty()) return;
        Node* ptr = first;
        while (ptr) {
            writeFile << ptr->word << ": " << ptr->counter << std::endl;
            ptr = ptr->nextItem;
        }
        writeFile << std::endl;
    };
};
*/

/* Сортировка
void partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;

    // Проходим по списку, сравнивая каждый элемент с pivot
    while (pivot != NULL && pivot->next != NULL) {
        if (pivot->data < pivot->next->data) {
            prev = pivot;
            pivot = pivot->next;
        } else {
            prev->next = pivot->next;
            pivot->next = prev;
            pivot = pivot->next;
        }
    }

    // Если pivot является последним элементом, то ничего не делаем
    if (pivot == end) {
        return;
    }

    // Устанавливаем pivot в правильное положение
    pivot->next = pivot->next->next;

    // Находим конечный узел левой половины (список перед pivot)
    Node* left = getTail(pivot->next);

    // Повторяем для левого списка
    partition(left, pivot->next, newHead, newEnd);

    // Наконец, повторяем для правого списка
    partition(pivot, end, newEnd, NULL);
}
*/
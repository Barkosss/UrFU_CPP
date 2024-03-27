#include<iostream>
#include<fstream>
#include<string>

#include "List.h"

using std::string;


List::Node::Node(string word): word(word), counter(0), nextItem(nullptr) {};

// Проверка, пустой ли список
bool List::is_empty() {
    return first == nullptr;
}

// Добавить элемент в список
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

// Добавить +1 к счётчику
void List::add(string word) {
    Node *ptr = first;
    while(ptr) {
        if (ptr->word == word) {
            ptr->counter++;
        }
        ptr = ptr->nextItem;
    }
};

// Сортировка
void List::sort() {
    Node *ptrFirst = first;
    Node *ptrSecond;

    // std::string word;
    // unsigned long counter;

    std::string tempWord;
    unsigned long tempCounter;
    /* Сортировка
    Сначала берём первый элемент из списка
    Берём второй элемент из списка
    Сравниваем первый и второй элементы,
    если правый больше, чем левый, то меняем местами, иначе нет
    Теперь, берём третий элемент и сравниваем с первым

    Когда дошли до конца, то теперь сравниваем второй элемент с третьим, второй с четвёртым и так далее
    Пока не дойдём до конца как с первой переменной (ptrFirst), так и со второй (ptrSecond)
    */
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

// Вывести информацию в файл
void List::print(std::ofstream&writeFile) {
    if (is_empty()) return;
    Node* ptr = first;
    while (ptr) {
        writeFile << ptr->word << ": " << ptr->counter << std::endl;
        ptr = ptr->nextItem;
    }
    writeFile << std::endl;
};
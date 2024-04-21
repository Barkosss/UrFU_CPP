template <typename Type>
class Vector {
private:
    struct Node {
        
    };
    unsigned int size = 0;

public:
    Vector(): 

    // Добавить элемент в конец списка
    Type push_back(int value) {}
    
    // Добавить элемент в начало списка
    Type push_front(int value) {}

    // Удалить последний элемент
    Type pop_back() {}

    // Удалить первый элемент
    Type pop_front() {}

    // Посмотреть последний элемент списка
    Type peek_back() {}

    // Посмотреть первый элемент списка
    Type peek_front() {}

    // Узнать длину списка
    unsigned int size() {}
};
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

/*
Написать шаблон стека и программу построения обратной польской нотации
выражения и вычисления его значения.
*/

using std::abs;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::map;

ifstream inFile("input.txt");

// Список приоритетов операторов
map<char, int> operationPriority {
    {')', 0},
    {'(', 0},
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}
};


int pow(int number, int degree) {
    int result = number;
    for(int indexDegree = 1; indexDegree < degree; indexDegree++) {
        result *= number;
    }
    return result;
}

bool isNumber(string number) {
    if (number.length() > 1) {
        return true;
    } else {
        return !operationPriority[number[0]];
    }
}

// Элемент стэка
template<typename Type>
struct Node {
    Type strValue;

    Node* prevNode;
    Node* nextNode;

    Node(Type strValue): strValue(strValue), prevNode(nullptr), nextNode(nullptr) {};
};

// Класс для стэка
template<typename Type>
class Stack {
private:
    Node<Type>* stackTailNode;
public:
    Stack<Type>(): stackTailNode(nullptr) {};

    bool isEmpty() {
        return stackTailNode == nullptr;
    }

    void push(const Type& strValue) {
        if (!stackTailNode) {
            stackTailNode = new Node(strValue);
            return;
        }

        auto* ptr = new Node(strValue);
        ptr->prevNode = stackTailNode;
        stackTailNode = ptr;
    }

    Type pop() {
        Type strValue = stackTailNode->strValue;
        stackTailNode = stackTailNode->prevNode;
        return strValue;
    }

    Type getLast() {
        return stackTailNode->strValue;
    }

    void print() {
        for(Node<Type>* ptr = stackTailNode; ptr; ptr = ptr->prevNode) {
            cout << ptr->strValue << " ";
        }
        cout << endl;
    }
};


// Класс для вектора
class Vector {
private:
    Node<string>* arrHeadNode {};
    Node<string>* arrTailNode {};

public:
    int size {};

    Vector(): arrHeadNode(nullptr), arrTailNode(nullptr), size(0) {};
    Vector(const Vector &copy) {
        for(Node<string>* ptr = copy.arrHeadNode; ptr; ptr = ptr->nextNode) {
            push(ptr->strValue);
        }
    }

    void push(const string& strValue) {
        size++;
        if (!arrHeadNode) {
            arrHeadNode = arrTailNode = new Node(strValue);
            return;
        }

        arrTailNode->nextNode = new Node(strValue);
        arrTailNode = arrTailNode->nextNode;
    }

    string get(int findIndex) {
        findIndex = (findIndex >= 0) ? (findIndex) : (size + findIndex);
        Node<string>* ptr = arrHeadNode;
        for(int index = 0; index < findIndex; index++, ptr = ptr->nextNode);
        return ptr->strValue;
    }

    string shift() {
        string strValue = arrHeadNode->strValue;
        arrHeadNode = arrHeadNode->nextNode;
        size--;
        return strValue;
    }

    void print() {
        for(Node<string>* ptr = arrHeadNode; ptr; ptr = ptr->nextNode) {
            cout << ptr->strValue << " ";
        }
        cout << endl;
    }
};

Vector parse(string expression) {
    Vector heap = Vector();
    Stack<string> stack = Stack<string>();
    int lenExpression = expression.length();

    for(int index = 0; index < lenExpression; index++) {
        char currSymbol = expression[index], nextSymbol = expression[index + 1], prevSymbol;
        if (index) prevSymbol = expression[index - 1];

        switch(currSymbol) {
            case '(': { // Встретилась открывающая скобка
                if (operationPriority[nextSymbol] && nextSymbol != '-' && nextSymbol != '(') {
                    cout << "(1) Expression is incorrect" << endl;
                    exit(401);
                }

                stack.push("("); // Добавляем в стэк скобку
                break;
            }
            case ')': { // Встретилась закрывающая скобка
                if (operationPriority[prevSymbol] && prevSymbol != '-' && prevSymbol != ')') {
                    cout << "(3) Expression is incorrect" << endl;
                    exit(401);
                }

                while(!stack.isEmpty() && stack.getLast() != "(") {
                    heap.push(stack.pop()); // Последний элемент стека переносим в кучу
                }

                // Удаляем "(" из стека
                stack.pop();
                break;
            }

            case '-': { // Встретился минус\
                // Если встретилось отрицательное число
                if (!index || !isdigit(prevSymbol) && isdigit(nextSymbol)) {
                    heap.push(std::to_string(-1 * atoi(&nextSymbol)));
                    index++;
                    break;
                }
            }
            case '+': {}// Встретился плюс
            case '*': {}// Встретился умножить
            case '/': { // Встретился делить

                // Если попалась операция, которая имеет выше приоритетом, чем последняя операция в стэке
                if (stack.isEmpty() || operationPriority[currSymbol] > operationPriority[stack.getLast()[0]]) {
                    stack.push(string(1, currSymbol));
                }
                    // Если попалась операция, которая имеет приоритет не выше
                else {
                    while(!stack.isEmpty() && stack.getLast() != "(" && operationPriority[currSymbol] <= operationPriority[stack.getLast()[0]]) {
                        heap.push(stack.pop());
                    }
                    stack.push(string(1, currSymbol)); // Добавляем текущую операцию в стэк
                }
                break;
            }
            case '^': { // Встретился возведение в степень
                stack.push("^");
                break;
            }

            default: { // Встретилась не операция (Число или сторонний символ)
                if (currSymbol == ' ') {
                    continue;
                }

                int chrNumber = (int)currSymbol - 48;
                if (chrNumber < 0 || 9 < chrNumber) {
                    cout << "(4) Expression is incorrect" << endl;
                    exit(401);
                }

                int number = chrNumber;
                currSymbol = expression[++index];
                chrNumber = (int)currSymbol - 48;
                while(0 <= chrNumber && chrNumber <= 9) {
                    number = number * 10 + chrNumber;
                    currSymbol = expression[++index];
                    chrNumber = (int)currSymbol - 48;
                }

                heap.push(std::to_string(number));
                index--;
                break;
            }
        }
    }

        while(!stack.isEmpty()) {
            heap.push(stack.pop());
    }

    return heap;
}

int execute(Vector& heap) {
    Stack<long double> stack = Stack<long double>();

    while(heap.size) {
        string elem = heap.shift();

        if (isNumber(elem)) {
            stack.push(stoi(elem));
            continue;
        }

        switch(elem[0]) {
            case '+': {
                stack.push(stack.pop() + stack.pop());
                break;
            }

            case '-': {
                long double two = stack.pop();
                long double one = stack.pop();
                //cout << one << " - " << two << " = " << one - two << endl; // DEBUG
                stack.push(one - two);
                break;
            }

            case '*': {
                stack.push(stack.pop() * stack.pop());
                break;
            }

            case '/': {
                long double two = stack.pop();
                long double one = stack.pop();
                stack.push(one / two);
                break;
            }

            case '^': {
                long double two = stack.pop();
                long double one = stack.pop();
                stack.push(pow(one, two));
                break;
            }
        }
    }

    return stack.getLast();
}


int main() {
    if (inFile.fail()) {
        cout << "File \"input.txt\" is not found!" << endl;
        return 404;
    }

    string expression;
    std::getline(inFile, expression);

    Vector heap = parse(expression);

    int result = execute(heap);
    cout << expression << " = " <<  result << endl;

    return 0;
}
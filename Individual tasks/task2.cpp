#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

/*
 * 2. В файле записаны целые числа.
 * Вывести все различные числа, встречающиеся в файле,
 * и для каждого указать,
 * сколько раз оно встретилось в исходном файле.
 * Использовать динамические списки.
 */

struct Node {
    long value;
    unsigned long counter;

    Node* nextNode;
    Node(long value): value(value), counter(1), nextNode(nullptr) {};
};

class List {
private:
    Node* headNode;
    Node* tailNode; 

public:
    unsigned countElements;
    
    List(): countElements(0), headNode(nullptr), tailNode(nullptr) {};

    Node operator[](int index) {
        Node* ptr = headNode;
        while(index) {
            ptr = ptr->nextNode;
            index--;
        }
        return *ptr;
    }

    bool inList(long value) {
        for(Node* node = headNode; node; node = node->nextNode) {
            if (node->value == value) {
                return true;
            }
        }

        return false;
    }

    void push(long value) {

        if (!headNode) {
            headNode = new Node(value);
            tailNode = headNode;
            countElements++;
            return;
        }

        if (!inList(value)) {
            countElements++;
            tailNode->nextNode = new Node(value);
            tailNode = tailNode->nextNode;
        } else {
            for(Node* ptr = headNode; ptr; ptr = ptr->nextNode) {
                if (ptr->value == value) {
                    ptr->counter++;
                    break;
                }
            }
        }
    }
};

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    long value;

    List list = List();
    while(!inFile.eof()) {
        inFile >> value;
        list.push(value);
    };


    outFile << "Number: Counter" << endl;
    for(unsigned indexNumber = 0; indexNumber < list.countElements; indexNumber++) {
        outFile << list[indexNumber].value << ": " << list[indexNumber].counter << endl;
    }

    cout << "Program is done!" << endl;

    return 0;
}
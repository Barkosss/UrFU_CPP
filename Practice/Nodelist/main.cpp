#include<fstream>

struct Node {
    long long value;
    unsigned long counter;
    Node* next;
    Node(long long value): value(value), counter(0), next(nullptr) {};
};

class List {
    Node* head;
public:

    Node* getHead();
    void add(long long value);
};

Node* List::getHead() {
   return head;
}

void List::add(long long value) {

    for(Node* index = getHead();; index->next) {
        if (index->value == value) {
            index->counter++;
            return;
        }
    }

    new Node(value);
}

void printList(List head, std::ofstream&writeFile) {
    

    /*
    Node* ptr = head;
    while (ptr) {
    cout << ptr->key << " -> ";
    ptr = ptr->next;
    }
    cout << "nullptr";
    */
}

int main() {
    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    if (!readFile.is_open() || !writeFile.is_open()) {
        return 404;
    }

    long long number;
    List listNumber;
    while(!readFile.eof()) {
        readFile >> number;
        listNumber.add(number);
    }

    printList(listNumber, writeFile);

    return 0;
}
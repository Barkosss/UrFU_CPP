#include<iostream>
#include<string>

#include "stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack stack;
    int counterNumber;
    //cout << "Enter counter number: "; cin >> counterNumber;

    stack.push(9);
    stack.push(1);
    stack.push(3);
    stack.push(10);
    stack.push(2);
    stack.push(5);
    stack.push(20);
    stack.push(7);


    while(!stack.is_empty()) {
        cout << "Value: " << stack.peek() << " | Max: " << stack.getMax() << endl;
        stack.pop();
    }

    return 0;
}
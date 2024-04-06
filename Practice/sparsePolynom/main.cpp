#include<iostream>
#include<fstream>

#include "Sparse.h"

int main() {
    std::ifstream readFile("main.txt");
    char operation;
    unsigned long long counterOne = 0, counterTwo = 0;
    unsigned long long degree; long double factor;
    readFile >> counterOne;

    List onePolynom = List(counterOne);
    for(int index = 0; index < counterOne; index++) {
        readFile >> factor >> degree;
        onePolynom.push(factor, degree);
    }
    onePolynom.sort();

    readFile >> operation;

    readFile >> counterTwo;
    List twoPolynom = List(counterTwo);
    for(int index = 0; index < counterTwo; index++) {
        readFile >> factor >> degree;
        twoPolynom.push(factor, degree);
    }
    twoPolynom.sort();

    List result = (operation == '+') ? (onePolynom + twoPolynom) : (onePolynom * twoPolynom);
    result.sort();
    result.print();

    readFile.close();
    return 0;
}
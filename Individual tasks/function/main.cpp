#include<iostream>
#include<fstream>

std::ifstream readFile("input.barsik");

void f1(long double a, long double b, long double eps, char indexMethod) {

}

void f2(long double a, long double b, long double eps, char indexMethod) {
    
}

void f3(long double a, long double b, long double eps, char indexMethod) {
    
}

int main() {
    long double a, b, eps;
    char indexFunc, indexMethod;

    readFile >> a >> b >> eps >> indexFunc >> indexMethod;

    if (indexFunc == '1') {
        f1(a, b, eps, indexMethod);
    } else if (indexFunc == '2') {
        f2(a, b, eps, indexMethod);
    } else {
        f3(a, b, eps, indexMethod);
    }

    return 0;
}
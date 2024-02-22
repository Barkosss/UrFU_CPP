#include <iostream>
#include "sum.cpp"
#include "sub.cpp"
#include "minus.cpp"
#include "Complex.h"

int main() {
    int a = 1, b = 5;
    int resultSum = Sum(a, b);
    std::cout << a << " + " << b << " = " << resultSum << std::endl;
    
    int resultMinus = Minus(a, b);
    std::cout << a << " - " << b << " = " << resultMinus << std::endl;
    
    int resultSub = Sub(a, b);
    std::cout << a << " * " << b << " = " << resultSub << std::endl;

    Complex cmp;
    cmp.Re = 1;
    cmp.Im = 1;
    return 0;
}
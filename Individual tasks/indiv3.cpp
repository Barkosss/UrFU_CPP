#include<iostream>
#include<fstream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

/*
В файле заданы строки из 5-ти чисел:
    - границы отрезка,
    - точность,
    - номер функции,
    - номер метода.

Номер функции = {1,2,3}, где
    1. f(x) = 2 - x,
    2. f(x) = x^3,
    3. f(x) = cos(x).

Номер метода = {1,2,3}, где
    1. Средних прямоугольников,
    2. Трапеций,
    3. Симпсона.

На заданном отрезке с заданной точностью вычислить приближенно
значение интеграла от заданной функции заданным методом.
*/

// Func: 2 - x;
long double oneFunc(long double x) {
    return 2 - x;
}

// Func: x^3;
long double twoFunc(long double x) {
    return pow(x, 3);
}

// Func: cos(x);
long double threeFunc(long double x) {
    return cos(x);
}

// Method: Middle box;
long double oneMethod(long double x) {
    // ...

    return 0;
}

// Method: Trapezoids
long double twoMethod(long double x) {
    // ...

    return 0;
}

// Method: Simpson
long double threeMethod(long double x) {
    // ...
}

long double getIntegral(long double leftBorder, long double rightBorder, long double accuracy, long double (*func)(long double), long double (*method)(long double)) {
    long double result;



    return result;
}


int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    unsigned indexFunction, indexMethod;
    long double leftBorder, rightBorder, accuracy;

    inFile >> leftBorder >> rightBorder >> accuracy >> indexFunction >> indexMethod;
    long double (*functions[3])(long double) { oneFunc, twoFunc, threeFunc };
    long double (*methods[3])(long double) { oneMethod, twoMethod, threeMethod };
    long double result = getIntegral(leftBorder, rightBorder, accuracy, functions[indexFunction], methods[indexMethod]);

    outFile << "Result: " << result << endl;

    return 0;
}
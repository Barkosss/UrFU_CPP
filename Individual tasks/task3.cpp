#include<iostream>
#include<fstream>

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
    1. f(x)=2 - x;
    2. f(x)=x^3;
    3. f(x)=cos(x).

Номер метода = {1,2,3}, где
    1. средних прямоугольников;
    2. трапеций;
    3. Симпсона.

На заданном отрезке с заданной точностью вычислить приближенно
значение интеграла от заданной функции заданным методом.
*/


int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    unsigned indexFunction, indexMethod;
    long double leftBorder, rightBorder, accuracy;

    inFile >> leftBorder >> rightBorder >> accuracy >> indexFunction >> indexMethod;



    return 0;
}
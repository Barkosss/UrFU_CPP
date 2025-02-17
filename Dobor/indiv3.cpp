#include <iostream>
#include <fstream>
#include <cmath>

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
long double oneMethod(long double (*func)(long double), long double left, long double right, long double eps) {
    int n = 2;
    long double h, integral_prev, integral = 0.0;

    do {
        integral_prev = integral;
        integral = 0.0;
        h = (right - left) / n;

        for (int i = 0; i < n; ++i) {
            long double x_mid = left + h * (i + 0.5);
            integral += func(x_mid);
        }
        integral *= h;
        n *= 2;
    } while (std::fabs(integral - integral_prev) > eps);

    return integral;
}

// Method: Trapezoids
long double twoMethod(long double (*func)(long double), long double left, long double right, long double eps) {
    int n = 2;
    long double h, integral_prev, integral = 0.0;

    do {
        integral_prev = integral;
        integral = 0.0;
        h = (right - left) / n;

        integral += 0.5 * (func(left) + func(right));
        for (int i = 1; i < n; ++i) {
            long double x = left + i * h;
            integral += func(x);
        }
        integral *= h;
        n *= 2;
    } while (std::fabs(integral - integral_prev) > eps);

    return integral;
}

// Method: Simpson
long double threeMethod(long double (*func)(long double), long double left, long double right, long double eps) {
    int n = 2;
    long double h, integral_prev, integral = 0.0;

    do {
        integral_prev = integral;
        integral = 0.0;
        h = (right - left) / n;

        integral += func(left) + func(right);
        for (int i = 1; i < n; ++i) {
            long double x = left + i * h;
            integral += (i % 2 == 0 ? 2 : 4) * func(x);
        }
        integral *= h / 3.0;
        n *= 2;
    } while (std::fabs(integral - integral_prev) > eps);

    return integral;
}

// ...
long double getIntegral(long double(*func)(long double),
                        long double (*method)(long double (*)(long double), long double, long double, long double),
                        long double left, long double right, long double eps) {
    return method(func, left, right, eps);
}


int main() {
    ifstream inFile("inputIndiv3.txt");
    ofstream outFile("outputIndiv3.txt");
    unsigned indexFunction, indexMethod;
    long double leftBorder, rightBorder, accuracy;


    while (inFile >> leftBorder >> rightBorder >> accuracy >> indexFunction >> indexMethod) {
        long double (*functions[3])(long double) = {oneFunc, twoFunc, threeFunc};
        long double
        (*methods[3])(long double (*)(long double), long double, long double, long double) = {oneMethod, twoMethod,
                                                                                              threeMethod};
        long double result = getIntegral(functions[indexFunction - 1], methods[indexMethod - 1], leftBorder, rightBorder,
                                         accuracy);

        outFile << "Result: " << result << endl;
    }
    return 0;
}
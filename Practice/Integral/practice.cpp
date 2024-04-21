#include<iostream>

long double getValue(long double x, unsigned char func) {
    // 1. x^3;
    // 2. x^2 - 5;
    // 3. 1 / x;

    if (func == '1') {
        return x * x * x;
    } else if (func == '2') {
        return x * x - 5;
    } else {
        return 1 / x;
    }
}

long double MiddleTtriangle(long double a, long double b, long double eps, long double(*getValue)(long double, unsigned char), unsigned char func) {
    long double integral = getValue(a);
    long double move = (b - a) / 2;
    long double nextIntegral = integral * move;
    long double oldIntegral = 0;

    while(std::fabs(nextIntegral - oldIntegral) > eps) {
        oldIntegral = nextIntegral;
        for(long double point = 0; point < b; point += move) {
            integral += getValue(a + (b - a) / 2 + point * (b - a), func);
        }
        move /= 2;
        nextIntegral = integral * move;
    }
    return nextIntegral;
}


int main() {
    long double a, b, eps; unsigned char func;
    std::cout << "a: "; std::cin >> a; std::cout << std::endl;
    std::cout << "b: "; std::cin >> b; std::cout << std::endl;
    std::cout << "eps: "; std::cin >> eps; std::cout << std::endl;
    std::cout << "Func (1: x^3 | 2: x^2 - 5 | 3: 1/x): "; std::cin >> func; std::cout << std::endl;

    std::cout << "Result: " << MiddleTtriangle(a, b, eps, *getValue, func) << std::endl;

    return 0;
}





/*
#include<iostream>

long double getValue(long double x) {
    return x * x * x;
}

// long double RightSquare(...) // long double TrapezeSquare(...)
long double LeftSquare(long double a, long double b, long double eps, long double (*getValue)(long double)) {
    long double integral = getValue(a); // getValue(b); // (getValue(a) + getValue(b)) / 2;
    long double move = b - a;
    long double nextIntegral = integral * move;
    long double oldIntegral = 0;
    while(std::fabs(nextIntegral - oldIntegral) > eps) {
        oldIntegral = nextIntegral;
        for(long double point = a + move / 2; point < b; point += move) {
            integral += getValue(point);
        }
        move /= 2;
        nextIntegral = integral * move;
    }
    return nextIntegral;
}

int main() {

    long double a, b, eps;
    std::cout << "Enter left border: "; std::cin >> a;
    std::cout << "Enter right border: "; std::cin >> b;
    std::cout << "Enter accuracy: "; std::cin >> eps;

    std::cout << "Result: " << LeftSquare(a, b, eps, *getValue) << std::endl;
    return 0;
}
*/
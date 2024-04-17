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

    std::cout << "Result: " << LeftSquare(a, b, eps, *getValue) << std::endl;;
    return 0;
}
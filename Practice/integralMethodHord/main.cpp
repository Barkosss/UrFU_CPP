#include<iostream>


long double Differ(long double x) {
    long long result = 0.0;

    return result;
}

long double f1(long double x) {
    return x * x * x - 1;
}

long double f2(long double x) {
    return x * x - 5;
}

long double f3(long double x) {
    return x / 2;
}


void MethodHord(long double a, long double b, long double eps, long double(*f)(long double), long double x) {
    long double Xcurr, Xprev, Xnew;
    for(long double index = a; index < b; index++) {
        Xcurr = () / (f(Xprev) - f(p));
    }
}

int main() {
    long double a, b, eps, x;
    std::cout << "Enter a: "; std::cin >> a;
    std::cout << "Enter b: "; std::cin >> b;
    std::cout << "Enter eps: "; std::cin >> eps;
    std::cout << "Enter x: "; std::cin >> x;

    MethodHord(a, b, eps, f1, x);
    MethodHord(a, b, eps, f2, x);
    MethodHord(a, b, eps, f3, x);

    return 0;
}
#include<iostream>
#include<cmath>

long double getDifferValue(long double* function, long double x, long double (*getValue)(long double)) {
    long double eps = 0.00000001;
    long double differValue = (getValue(x + eps) - getValue(x)) / eps;
    
    return differValue;
}


long double getResult(long double a, long double b, long double eps, long double* function, unsigned long long counter, long double (*getValue)(long double), long double (*getDifferValue)(long double*, long double)) {
    long double X0; /* long double differValue = getDifferValue(function, counter); */
    long double I;

    if (getValue(a) * getDifferValue(function, getDifferValue(function, a))) {
        X0 = a;
    }
    else {
        X0 = b;
    }

    while(fabs(getValue(X0) >= eps)) {
        I = getValue(X0) / getDifferValue(function, X0);
        X0--;
    }

    return X0;
}


int main() {

    // ...

    return 0;
}
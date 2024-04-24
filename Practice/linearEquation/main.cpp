#include<iostream>

long double getValue(long double value) {
    // ...
}

long double function(long double a, long double b, long double eps, long double(*getValue)(long double)) {
    if (getValue(a) < eps) return a;
    if (getValue(b) < eps) return b;
    
    long double medianLine = a, getValueMedian;
    while(abs(getValue(medianLine)) >= eps) {
        medianLine = (a + b) / 2;
        getValueMedian = getValue(medianLine);

        if (getValue(a) * getValueMedian < 0) {
            b = medianLine;
        } else if (getValue(b) * getValueMedian < 0) {
            a = medianLine;
        }
    }

    return medianLine;
}

int main() {


    return 0;
}
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int SumDigits(long long number, long sum = 0) {
    if (!number) return sum;
    return SumDigits(number / 10, sum + (number % 10));
}

/* ЗАДАНИЕ 1
* Написать рекурсивную функцию, вычисляющую сумму цифр десятичной записи
* неотрицательного целого числа
*/

int main() {
    long long number;
    cout << "Number: "; cin >> number;
    cout << "Answer: " << SumDigits(number);
    return 0;
}
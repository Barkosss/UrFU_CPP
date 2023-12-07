#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int count = 0;
int SumDigits(int number) {
}

/* ЗАДАНИЕ 1
* Написать рекурсивную функцию, вычисляющую сумму цифр десятичной записи
* неотрицательного целого числа
*/

int main() {
    long long number;
    cout << "Number: "; cin >> number;
    cout << SumDigits(number);
    return 0;
}
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int count = 0;
int SumNumber(int numberFrom, int numberTo) {
    if (count == numberTo) return 0; count++;
    return numberFrom + SumNumber(numberFrom + 1, numberTo);
}

/* ЗАДАНИЕ 1
* Написать рекурсивную функцию, вычисляющую умму цифр десятичной записи
* неотрицательного целого числа
*/

int main() {
    int number;
    cout << "Number: "; cin >> number;
    if (number < 0) { cout << "The number must be non-negative" << endl; return 0; };
    cout << SumNumber(1, number);
    return 0;
}
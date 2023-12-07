#include<iostream>

using std::cin;
using std::cout;
using std::endl;

// РАБОТАЕТ НЕКОРРЕКТНО
bool CheckNumber(long long number) {
    if (number) {
        if (number < 10) return 1;
        if ((number / 10) % 10 > number % 10) {
            return CheckNumber(number / 10);
        } else {
            return 0;
        }
    }
    return 1;
}

/* ЗАДАНИЕ 2
* Написать рекурсивную функицю, проверяющую, что последовательность цифр
* десятичной записи числа является убывающей
*/

int main() {
    long long number;
    cout << "Enter number: "; cin >> number;
    cout << "Answer: " << ((CheckNumber(number)) ? ("True") : ("False")) << endl;
    return 0;
}
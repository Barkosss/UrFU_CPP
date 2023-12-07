#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Алфавит
string alphabet = "0123456789ABCDEF";
string Convert(int number, int base, string result = "") {
    if (number < base) return alphabet[number] + result;
    return Convert(number / base, base, alphabet[number % base] + result);
}


/* ЗАДАНИЕ 3
* Написать рекурсивную функцию,
* получающую р-ичную запись целого неотрицательного числа (2 <= p <= 16)
*/

int main() {
    int number, base;
    cout << "Enter number (number >= 0): "; cin >> number;
    cout << "Enter base (2 <= base <= 16): "; cin >> base;
    if (number < 0) { cout << "The number must be positive" << endl; return 0; };
    if (base < 2 || 16 < base) { cout << "The base should be from 2 to 16" << endl; return 0; };
    cout << number << " (10) = " << Convert(number, base) << " (" << base << ")" << endl;
    return 0;
}
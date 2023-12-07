#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int i = 0;
char ArrayNumber[1] { '0' };
char ArrayBase[6] { 'A', 'B', 'C', 'D', 'E', 'F' };

// Convert - перевод числа number в base-систему
// number - число, которое переводим
// base - основание системы счисления
int remain; // Остаток числа
int Convert(int number, int base) {
    if (number == 0) return 1;
    remain = number % base;
    cout << endl << remain;
    if (remain > 9) ArrayNumber[i] = ArrayBase[remain - 10];
    else ArrayNumber[i] = remain;
    i++;
    return Convert(number / base, base);
}


/* ЗАДАНИЕ 3
* Написать рекурсивную функцию,
* получающую р-ичную запись целого неотрицательного числа (2 <= p <= 16)
*/

int main() {
    int number, base;
    cout << "Enter number (number >= 0): "; cin >> number;
    cout << "Enter base (2 <= base <= 16): "; cin >> base;
    if (number < 0) { cout << "" << endl; return 0; };
    if (base < 2 || 16 < base) { cout << "" << endl; return 0; };
    cout << number << " (10) = ";
    Convert(number, base);
    for(int index = i - 1; index >= 0; index--) cout << ArrayNumber[index];
    cout << " (" << base << ")" << endl;
    return 0;
}
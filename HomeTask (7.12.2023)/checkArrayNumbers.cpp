#include<iostream>

using std::cin;
using std::cout;
using std::endl;


void CheckArray(int* Array, int countNumbers, int index) {
    if (index == countNumbers) { cout << "True" << endl; return; };

    if (Array[index - 1] <= Array[index]) { cout << "False" << endl; return; }
    
    return CheckArray(Array, countNumbers, index + 1);
}

/* ЗАДАНИЕ 2
* Написать рекурсивную функицю, проверющую, что последовательность цифр
* десятичной записи числа является убывающей
*/

int main() {
    int countNumbers;
    cout << "Enter counter numbers: "; cin >> countNumbers;
    int *Array = new int[countNumbers]{0};

    // Запись в массив чисел
    for(int i = 0; i < countNumbers; i++) cin >> Array[i];
    CheckArray(Array, countNumbers, 1);
    return 0;
}
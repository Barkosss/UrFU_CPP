#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;

int i = 0;
int GetMaxElement(int *Array, int lenArray, int maxNumber = -1 * INT_MAX) {
    if (i == lenArray) return maxNumber;
    maxNumber = max(Array[i], maxNumber); i++;
    return GetMaxElement(Array, lenArray, maxNumber);
}


/* ЗАДАНИЕ 4
* Написать рекурсивную функцию,
* возвращающая максимальный элемент массива
*/

int main() {
    int lenArray;
    cout << "Enter counter number: "; cin >> lenArray;
    int* Array = new int[lenArray];
    for(int i = 0; i < lenArray; i++) cin >> Array[i];
    cout << GetMaxElement(Array, lenArray) << endl;
    return 0;
}
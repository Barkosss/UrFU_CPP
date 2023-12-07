#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;

int GetMaxElement(int *Array, int lenArray, int maxNumber = -1 * INT_MAX, int index = 0) {
    if (index == lenArray) return maxNumber;
    maxNumber = max(Array[index], maxNumber);
    return GetMaxElement(Array, lenArray, maxNumber, index + 1);
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
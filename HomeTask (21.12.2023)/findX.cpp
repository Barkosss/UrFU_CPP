#include<iostream>

using std::cin;
using std::cout;
using std::endl;

// Функция для поиска элемента в массиве | Без рекурсии
int WithoutRecursion(int *array, int findNumber, int rightIndex, int leftIndex = 0) {

    int middleIndex;
    while (leftIndex != rightIndex) {
        middleIndex = (leftIndex + rightIndex) / 2;

        // Если array[middleIndex] равен нашему числу, то вернуть middleIndex;
        if (array[middleIndex] == findNumber) return middleIndex;

        // Если середина больше, чем наше число, то мы смотрим левую половину
        if (array[middleIndex] > findNumber) rightIndex = middleIndex - 1;

        // Если середина меньше, чем наше число, то мы смотрим правую половину
        if (array[middleIndex] < findNumber) leftIndex = middleIndex + 1;
    }
    
    if (leftIndex == rightIndex && array[leftIndex] != findNumber) return -1;
    if (leftIndex == rightIndex && array[leftIndex] == findNumber) return leftIndex;

    return 0;
}


// Основная функция
int main() {
    int countNumbers; // Количество чисел в массиве
    cout << "Enter counter numbers: "; cin >> countNumbers;
    int *Array = new int[countNumbers];
    for(int i = 0; i < countNumbers; i++) cin >> Array[i];

    // Проврека на корректный массив
    for(int i = 1; i < countNumbers; i++) {
        if (Array[i - 1] > Array[i]) {
            cout << "The array is unordered in ascending order!" << endl;
            return 1;
        }
    }

    int findNumber; // Число, которое надо найти
    while (findNumber ) {
        cout << "Specify the element to be found in the array: "; cin >> findNumber;
    }
    int answerWithoutRecursion = WithoutRecursion(Array, findNumber, countNumbers - 1);
    cout << "Answer without recursion: " << answerWithoutRecursion << " (Debug: " << answerWithoutRecursion + 1 << ")" << endl;

    return 0;
}
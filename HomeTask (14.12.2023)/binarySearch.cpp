#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Функция для поиска элемента в массиве | Через рекурсию
int WithRecursion(int *array, int findNumber, int leftIndex, int rightIndex) {
    if (leftIndex == rightIndex && array[leftIndex] != findNumber) return -1;
    if (leftIndex == rightIndex && array[leftIndex] == findNumber) return leftIndex;

    int middleIndex = (leftIndex + rightIndex) / 2; // Середина массива

    // Если array[middleIndex] равен нашему числу, то вернуть middleIndex;
    if (array[middleIndex] == findNumber) return middleIndex;

    // Если середина больше, чем наше число, то мы смотрим левую половину
    if (array[middleIndex] > findNumber) return WithRecursion(array, findNumber, leftIndex, middleIndex - 1);
    
    // Если середина меньше, чем наше число, то мы смотрим правую половину
    if (array[middleIndex] < findNumber) return WithRecursion(array, findNumber, middleIndex + 1, rightIndex);

    return 0;
}

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
    int findNumber; // Число, которое надо найти
    cout << "Specify the element to be found in the array: "; cin >> findNumber;

    int countNumbers; // Количество чисел в массиве
    cout << "Enter counter numbers: "; cin >> countNumbers;
    int *Array = new int[countNumbers];
    for(int i = 0; i < countNumbers; i++) cin >> Array[i];

    // 4 54 54 54 54 231 231 321 545 564

    // Проврека на корректный массив
    for(int i = 1; i < countNumbers; i++) {
        if (Array[i - 1] > Array[i]) {
            cout << "The array is unordered in ascending order!" << endl;
            return 1;
        }
    }

    // Ответ с рекурсией
    int answerWithRecursion = WithRecursion(Array, findNumber, 0, countNumbers - 1);
    cout << "Answer with recursion: " << answerWithRecursion << " (Debug: " << answerWithRecursion + 1 << ")" << endl;

    // Ответ без рекурсии
    int answerWithoutRecursion = WithoutRecursion(Array, findNumber, countNumbers - 1);
    cout << "Answer without recursion: " << answerWithoutRecursion << " (Debug: " << answerWithoutRecursion + 1 << ")" << endl;

    return 0;
}
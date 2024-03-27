#include "Polygon.h"

// Сортировка Хоара
int partOfSortHoara(Polygon*arrayPolygon, int left, int right) {
    Polygon pivot = arrayPolygon[(left + right) / 2];
    Polygon temp;
    while(left <= right) { // ...
    
        // Если левый элемент больше опорному, двигаемся дальше
        while(arrayPolygon[left].GetDiagonal() > pivot.GetDiagonal()) {
            left++;
        }

        // Если правый элемент меньше опорном, двигаемся дальше
        while(arrayPolygon[right].GetDiagonal() < pivot.GetDiagonal()) { 
            right--;
        }

        if (left <= right) { // ... -> Поменяем местами
            temp = arrayPolygon[left];
            arrayPolygon[left] = arrayPolygon[right];
            arrayPolygon[right] = temp;
            left++; right--;
        }

    }
    return left;
}

// Сортировка Хоара
void quickSortHoara(Polygon*array, int start, int end) {
    if (start >= end) return;
    int rightStart = partOfSortHoara(array, start, end);
    quickSortHoara(array, start, rightStart - 1);
    quickSortHoara(array, rightStart, end);
}
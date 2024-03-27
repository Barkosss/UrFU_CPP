#include "sortHoara.h"
#include "Polygon.h"

// Сортировка Хоара
int partOfSortHoara(Polygon*arrayPolygon, int left, int right) {
    Polygon pivot = arrayPolygon[(left + right) / 2];
    Polygon temp;
    while(left <= right) { // ...
    
        // Если левый элемент больше опорному, двигаемся дальше
        while(arrayPolygon[left].getSquare() < pivot.getSquare()) {
            left++;
        }

        // Если правый элемент меньше опорном, двигаемся дальше
        while(pivot.getSquare() < arrayPolygon[right].getSquare()) { 
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
#include<cmath>

#include "Polygon.h"

long double Polygon::getSquare() {
    return square;
}

long double Polygon::getX(int indexPoint) {
    return this->array[indexPoint].x;
}

long double Polygon::getY(int indexPoint) {
    return this->array[indexPoint].y;
}

int Polygon::getCounterPoints() {
    return this->counterPoints;
}

void Polygon::setPolygon(int counter, Point* array) {
    counterPoints = counter;
    array = array;
}

// Вычислить площадь
long double Polygon::computeSquare() {
    // Формула площади Гаусса
    int counterPoints = counterPoints;
    long double oneSum = 0, twoSum = 0, currSquare;
    for(int index = 0; index < counterPoints - 1; index++) {
        oneSum += this->array[index].x * this->array[index + 1].y;
    }
    oneSum += this->array[counterPoints - 1].x * this->array[0].y;

    for(int index = 0; index < counterPoints - 1; index++) {
        twoSum += this->array[index + 1].x * this->array[index].y;
    }
    twoSum -= this->array[0].x * this->array[counterPoints - 1].y;

    currSquare = 0.5 * abs(oneSum - twoSum);
    square = currSquare;

    return currSquare;
}
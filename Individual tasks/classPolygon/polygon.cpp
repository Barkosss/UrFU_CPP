#include "polygon.h"


// Создать точки для полинома
void Polygon::createPoints(unsigned long long counterPoints) {
    array = new Point[counterPoints];
};

// Установить точки (X,Y)
void Polygon::setPoint(unsigned long long indexPoint, long double pointX, long double pointY) {
    array[indexPoint].x = pointX;
    array[indexPoint].y = pointY;   
};

// Вычислить площадь
long double Polygon::ComputeSquare() {
    long double result = 0.0;

    // Формула площади Гаусса
    long double oneSum = 0, twoSum = 0;
    for(int index = 0; index < counterPoints - 1; index++) {
        oneSum += this->array[index].x * this->array[index + 1].y;
    }
    oneSum += this->array[counterPoints - 1].x * this->array[0].y;

    for(int index = 0; index < counterPoints - 1; index++) {
        twoSum += this->array[index + 1].x * this->array[index].y;
    }
    twoSum -= this->array[0].x * this->array[counterPoints - 1].y;

    result = 0.5 * (-1 * (oneSum - twoSum < 0) * (oneSum - twoSum));

    square = result;
    return result;
};

// Получить площадь
long double Polygon::getSquare() {
    return square;
}

// Получить количество точек
unsigned long long Polygon::getCounterPoints() {
    return counterPoints;
}

// Получить точку X
long double Polygon::getX(unsigned long long indexPoint) {
    return array[indexPoint].x;
}

// Получить точку Y
long double Polygon::getY(unsigned long long indexPoint) {
    return array[indexPoint].y;
}
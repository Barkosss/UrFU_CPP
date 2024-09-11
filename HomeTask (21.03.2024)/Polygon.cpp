#include<cmath>

#include "Polygon.h"

long double Polygon::GetX(int indexPoint) {
    return arrayPoints[indexPoint].x;
}

long double Polygon::GetY(int indexPoint) {
    return arrayPoints[indexPoint].x;
}

// Получить периметр многоугольника
long double Polygon::GetPerimetr() {
    return perimeter;
}

// Получить диагональ многоугольника
long double Polygon::GetDiagonal() {
    return maxLengthDiagonal;
}

// Получить площадь многоугольника
long double Polygon::GetSquare() {
    return square;
}

// Получить количество точек
int Polygon::GetCounterVertices() {
    return counterVertices;
}

// Записсать периметр многоугольника
void Polygon::SetPerimetr(long double perimetr) {
    this->perimeter = perimeter;
}

// Записать маскимальную длину диагонали многоугольника
void Polygon::SetMaxLengthDiagonal(long double maxLengthDiagonal) {
    this->maxLengthDiagonal = maxLengthDiagonal;
}

// Записать площадь многоугольника
void Polygon::SetSquare(long double square) {
    this->square = square;
}

// Запись точек
void Polygon::SetPoints(Point *point) {
    this->arrayPoints = point;
}

// Запись количество вершин
void Polygon::SetCounterVertices(unsigned counterVertices) {
    this->counterVertices = counterVertices;
}


// Проверить, выпуклый ли многоугольник
bool Polygon::isConvex() {
    /*
D = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)

if D == 0 - точка на прямой
if D > 0 - точка справа от прямой
if D < 0 - точка слева от прямой
    */

    long double D;

    for(unsigned indexPoint = 0; indexPoint < counterVertices; indexPoint++) {
        for(int jndexPoint = indexPoint + 2; jndexPoint < counterVertices; jndexPoint++) {
            D = (arrayPoints[jndexPoint].x - arrayPoints[indexPoint].x) * (arrayPoints[indexPoint + 1].y - arrayPoints[indexPoint].y) - (arrayPoints[jndexPoint].y - arrayPoints[indexPoint].y) * (arrayPoints[indexPoint + 1].x - arrayPoints[indexPoint].x);

            if (D <= 0) {
                return false;
            }
        }

        for(unsigned jndexPoint = 0; jndexPoint < indexPoint; jndexPoint++) {
            D = (arrayPoints[jndexPoint].x - arrayPoints[indexPoint].x) * (arrayPoints[indexPoint + 1].y - arrayPoints[indexPoint].y) - (arrayPoints[jndexPoint].y - arrayPoints[indexPoint].y) * (arrayPoints[indexPoint + 1].x - arrayPoints[indexPoint].x);

            if (D <= 0) {
                return false;
            }
        }
    }

    return true;
}

// Вычислить диагональ
long double Polygon::ComputeDiagonal() {
    long double tempLengthDiagonal, currMaxLengthDiagonal = 0;

    for(unsigned indexPoint = 0; indexPoint < counterVertices; indexPoint++) {
        for(int jndexPoint = indexPoint + 2; jndexPoint < counterVertices; jndexPoint++) {
            tempLengthDiagonal = (arrayPoints[indexPoint].x - arrayPoints[jndexPoint].x) * (arrayPoints[indexPoint].x - arrayPoints[jndexPoint].x) + (arrayPoints[indexPoint].y - arrayPoints[jndexPoint].y) * (arrayPoints[indexPoint].y - arrayPoints[jndexPoint].y);

            currMaxLengthDiagonal = std::max(currMaxLengthDiagonal, tempLengthDiagonal);
        }

        for(unsigned jndexPoint = 0; jndexPoint < indexPoint; jndexPoint++) {
            tempLengthDiagonal = (arrayPoints[indexPoint].x - arrayPoints[jndexPoint].x) * (arrayPoints[indexPoint].x - arrayPoints[jndexPoint].x) + (arrayPoints[indexPoint].y - arrayPoints[jndexPoint].y) * (arrayPoints[indexPoint].y - arrayPoints[jndexPoint].y);

            currMaxLengthDiagonal = std::max(currMaxLengthDiagonal, tempLengthDiagonal);
        }
    }

    maxLengthDiagonal = currMaxLengthDiagonal;

    return currMaxLengthDiagonal;
}

// Вычислить периметр
long double Polygon::ComputePerimetr() {
    long double currPerimetr = 0.0;

    // От начальной точки до предпоследней точки
    for(int indexVertice = 0; indexVertice < counterVertices - 1; indexVertice++) {
        currPerimetr += sqrt((arrayPoints[indexVertice].x - arrayPoints[indexVertice + 1].x) * (arrayPoints[indexVertice].x - arrayPoints[indexVertice + 1].x) + (arrayPoints[indexVertice].y - arrayPoints[indexVertice + 1].y) * (arrayPoints[indexVertice].y - arrayPoints[indexVertice + 1].y));
    }

    // Последняя точка с начальная точка
    currPerimetr += sqrt((arrayPoints[0].x - arrayPoints[counterVertices - 1].x) * (arrayPoints[0].x - arrayPoints[counterVertices - 1].x) + (arrayPoints[0].y - arrayPoints[counterVertices - 1].y) * (arrayPoints[0].y - arrayPoints[counterVertices - 1].y));

    perimeter = currPerimetr;
    return currPerimetr;
}

// Вычислить площадь
long double Polygon::ComputeSquare() {
    // Формула площади Гаусса
    int counterPoints = this->GetCounterVertices();
    long double oneSum = 0, twoSum = 0, currSquare;
    for(int index = 0; index < counterPoints - 1; index++) {
        oneSum += this->arrayPoints[index].x * this->arrayPoints[index + 1].y;
    }
    oneSum += this->arrayPoints[counterPoints - 1].x * this->arrayPoints[0].y;

    for(int index = 0; index < counterPoints - 1; index++) {
        twoSum += this->arrayPoints[index + 1].x * this->arrayPoints[index].y;
    }
    twoSum -= this->arrayPoints[0].x * this->arrayPoints[counterPoints - 1].y;

    currSquare = 0.5 * abs(oneSum - twoSum);
    square = currSquare;

    return currSquare;
}
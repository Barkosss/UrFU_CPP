#include<iostream>
#include<cmath>

#include "getSquare.h"

using std::abs;

long double getSquare(Point&onePoint, Point&twoPoint,  Point&threePoint) {
    double oneX = onePoint.x;
    double oneY = onePoint.y;
    double twoX = twoPoint.x;
    double twoY = twoPoint.y;
    double threeX = threePoint.x;
    double threeY = threePoint.y;

    long double result = abs((twoX - oneX) * (threeY - oneY) - (threeX - oneX) * (twoY - oneY)) / 2;

    return result;
}
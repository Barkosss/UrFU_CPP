#include "straight.h"

// Проверить, есть ли пересечение прямых. Есть -> True
bool Straight::operator ==(Straight&right) {

    return true;
}

// Проверить, есть ли пересечение прямых. Есть -> False
bool Straight::operator !=(Straight&right) {

    return false;
}

// Получение точек пересечения
Straight getPointIntersection(Straight&left, Straight&right) {
    long double Xpoint, Ypoint;



    return {Xpoint, Ypoint};
}

Straight::Straight(long double userX, long double userY) {
    x = userX;
    y = userY;
}
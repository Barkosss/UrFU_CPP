#pragma once

struct Point {
    long double x;
    long double y;
};

class Polygon {
private:
    int counterPoints;
    Point *array;
    long double square;
public:
    long double getX(int indexPoint);
    long double getY(int indexPoint);
    int getCounterPoints();
    long double getSquare();
    void setPolygon(int counterPoints, Point* array);

    long double computeSquare();
};
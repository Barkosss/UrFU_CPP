#pragma once

struct Point {
    long double x;
    long double y;
};

class Polygon {
private:
    Point* array;
    unsigned long long counterPoints;
    long double square;

public:
    Polygon() {};
    void createPoints(unsigned long long counterPoints);
    void setPoint(unsigned long long indexPoint, long double pointX, long double pointY);
    long double ComputeSquare();
    long double getSquare();
    unsigned long long getCounterPoints();
    long double getX(unsigned long long indexPoint);
    long double getY(unsigned long long indexPoint);
};
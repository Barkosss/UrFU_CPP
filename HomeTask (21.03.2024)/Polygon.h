#pragma once

#include<fstream>

struct Point {
    long double x;
    long double y;


    Point(): x(0), y(0) {};
    Point(long double x, long double y): x(x), y(y) {};
};


class Polygon {
private:
    long double maxLengthDiagonal;
    long double perimeter;
    long double square;
    int counterVertices;
    Point *arrayPoints;

    void Copy(const Polygon&right) {
        maxLengthDiagonal = right.maxLengthDiagonal;
        perimeter = right.perimeter;
        square = right.square;
        counterVertices = right.counterVertices;
        arrayPoints = right.arrayPoints;
    }

public:

    // Get
    long double GetX(int indexPoint);    
    long double GetY(int indexPoint);
    long double GetPerimetr();
    long double GetSquare();
    long double GetDiagonal();
    int GetCounterVertices();

    // Post
    void SetPerimetr(long double perimetr);
    void SetMaxLengthDiagonal(long double maxLengthDiagonal);
    void SetSquare(long double square);
    void SetPoints(Point *point);
    void SetCounterVertices(unsigned counterVertices);

    // Compute
    bool isConvex();
    long double ComputeDiagonal();
    long double ComputePerimetr();
    long double ComputeSquare();

    Polygon(): maxLengthDiagonal(-1), perimeter(0), square(0), counterVertices(0), arrayPoints(nullptr) {};
    void operator=(const Polygon&right) { Copy(right); }
};
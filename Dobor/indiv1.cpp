#include<iostream>
#include<fstream>

/*
Написать класс, моделирующий многоугольники, возможно
невыпуклые. С его помощью решить следующую задачу: для
многоугольников, заданных в файле, вычислить площадь и выписать
их в новый файл, упорядочив по убыванию площади.
*/

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


// Struct Point
struct Point {
    long double x;
    long double y;
    Point* nextPoint;

    Point(): x(0), y(0) {};
    Point(long double x, long double y): x(x), y(y) {};
};

// Class: Polygon
class Polygon {
private:
    Point* headPoint;
    Point* tailPoint;
public:
    Polygon(): headPoint(nullptr), tailPoint(nullptr) {};

    // Push new point in Polygon
    void push(long double x, long double y) {
        if (!headPoint) {
            headPoint = tailPoint = new Point(x, y);
            return;
        }

        tailPoint->nextPoint = new Point(x, y);
        tailPoint = tailPoint->nextPoint;
    }

    Point operator[](unsigned index) {
        Point* point = headPoint;
        while(index) {
            index--;
            point = point->nextPoint;
        }

        return *point;
    };

    // Compare square of Polygon
    long double compareSquare(unsigned countPoints) {
        long double square = 0;

        for(int i = 0; i < countPoints - 1; i++) {
            square += (*this)[i].x * (*this)[i + 1].y;
        }

        square += (*this)[countPoints - 1].x * (*this)
        [0].y;

        for(int i = 0; i < countPoints - 1; i++) {
            square -= (*this)[i + 1].x * (*this)[i].y;
        }

        square -= (*this)[0].x * (*this)[countPoints - 1].y;

        return square / 2;
    }
};

// Сортировка массива
void sort(long double* arrSquares, unsigned countSquare) {
    long double temp;
    for(unsigned index = 0; index < countSquare; index++) {
        for(unsigned jndex = index + 1; jndex < countSquare; jndex++) {
            if (arrSquares[index] > arrSquares[jndex]) {
                temp = arrSquares[index];
                arrSquares[index] = arrSquares[jndex];
                arrSquares[jndex] = temp;
            }
        }
    }
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }

    unsigned countPolygons, countPoints;
    inFile >> countPolygons;

    long double x, y;
    long double* arrSquares = new long double[countPolygons];
    for(unsigned indexPolygon = 0; indexPolygon < countPolygons; indexPolygon++) {
        Polygon polygon = Polygon();
        inFile >> countPoints;

        for(unsigned indexPoint = 0; indexPoint < countPoints; indexPoint++) {
            inFile >> x >> y;
            polygon.push(x, y);
        }
        arrSquares[indexPolygon] = polygon.compareSquare(countPoints);
    }

    sort(arrSquares, countPolygons);
    for(unsigned index = 0; index < countPolygons; index++) {
        outFile << '#' << index << ": " << arrSquares[index] << endl;
    }

    delete[] arrSquares;
    return 0;
}

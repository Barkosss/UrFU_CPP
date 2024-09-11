#include<iostream>
#include<fstream>

#include "polygon.h"
#include "sortHoara.h"

/* !НЕДОДЕЛАН!

Код ошибки: 139

*/


/*
Написать  класс,  моделирующий  многоугольники,  возможно невыпуклые.
С  его  помощью  решить  следующую  задачу:
для многоугольников, заданных в файле, вычислить площадь и выписать
их в новый файл, упорядочив по убыванию площади.
*/

int main() {
    // ------------ Чтение многочленов ------------
    std::ifstream readFile("input.barsik");

    long double pointX, pointY;
    unsigned long long counterPolygons, counterPoints;
    readFile >> counterPolygons;

    Polygon* polygons = new Polygon[counterPolygons];
    for(unsigned long long indexPolygon = 0; indexPolygon < counterPolygons; indexPolygon++) {
        readFile >> counterPoints;

        polygons[indexPolygon].createPoints(counterPoints);
        for(unsigned long long indexPoint = 0; indexPoint < counterPoints; indexPoint++) {

            readFile >> pointX >> pointY;
            polygons[indexPolygon].setPoint(indexPoint, pointX, pointY);
        }
    }
    readFile.close();
    // ------------ Чтение многочленов ------------



    // ------------ Вычисление многочленов ------------
    quickSortHoara(polygons, 0, counterPolygons - 1);
    // ------------ Вычисление многочленов ------------



    // ------------ Запись многочленов ------------
    std::ofstream writeFile("output.barsik");
    for(int indexPolygon = 0; indexPolygon < counterPolygons; indexPolygon++) {
        writeFile << "#" << indexPolygon + 1 << ": ";
        writeFile << "S: " << polygons[indexPolygon].getSquare();

        counterPoints = polygons[indexPolygon].getCounterPoints();
        for(int indexPoint = 0; indexPoint < counterPoints; indexPoint++) {
            writeFile << "(x:" << polygons[indexPolygon].getX(indexPoint) << " | y:" << polygons[indexPolygon].getY(indexPoint) << ")\t";
        }

        writeFile << std::endl;
    }
    writeFile.close();
    // ------------ Запись многочленов ------------
    return 0;
}
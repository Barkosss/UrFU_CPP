#include<iostream>
#include<fstream>

#include "fileSystem.h"
#include "sortHoara.h"
#include "Polygon.h"

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {

    long double x, y;
    int counterPolygons, counterPoints;
    readFile >> counterPolygons;

    Polygon *polygons = new Polygon[counterPolygons];
    for(int indexPolygon = 0; indexPolygon < counterPolygons; indexPolygon++) {
        readFile >> counterPoints;
        Point *array = new Point[counterPoints];

        for(int indexPoint = 0; indexPoint < counterPoints; indexPoint++) {
            readFile >> x >> y;
            array[indexPoint].x = x;
            array[indexPoint].y = y;
        }
        polygons[indexPolygon].setPolygon(counterPoints, array);
    }

    // Сортировка - Хоар
    quickSortHoara(polygons, 0, counterPolygons - 1);

    int counterPointsPolygon;
    for(int indexPolygon = 0; indexPolygon < counterPolygons; indexPolygon++) {
        writeFile << "#" << indexPolygon + 1 << ": ";
        writeFile << "S: " << polygons[indexPolygon].getSquare();

        counterPointsPolygon = polygons[indexPolygon].getCounterPoints();
        for(int indexPoint = 0; indexPoint < counterPointsPolygon; indexPoint++) {
            writeFile << "(x:" << polygons[indexPolygon].getX(indexPoint) << " | y:" << polygons[indexPolygon].getY(indexPoint) << ")\t";
        }
        writeFile << std::endl;
    }

    readFile.close();
    writeFile.close();
    std::cout << "Write is end!" << std::endl;
}
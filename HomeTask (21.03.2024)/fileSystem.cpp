#include<iostream>
#include<fstream>

#include "fileSystem.h"
#include "sortHoara.h"
#include "Polygon.h"

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {
    long double x, y;
    int counterPolygons, counterPoints, counterConvexPolygons = 0, counterConvexPoints;

    readFile >> counterPolygons;

    Point *arrayPoints;
    Polygon *arrayPolygon = new Polygon[counterPolygons]{ Polygon() };
    for(int indexPolygons = 0; indexPolygons < counterPolygons; indexPolygons++) {
        Polygon polygon;
        readFile >> counterPoints;

        arrayPoints = new Point[counterPoints];
        for(int indexPoint = 0; indexPoint < counterPoints; indexPoint++) {
            readFile >> x >> y;
            arrayPoints[indexPoint] = Point(x, y);
        }

        polygon.SetCounterVertices(counterPoints);
        polygon.SetPoints(arrayPoints);

        if (!polygon.isConvex()) {
            continue;
        }

        polygon.ComputeDiagonal();
        polygon.ComputePerimetr();
        polygon.ComputeSquare();

        arrayPolygon[counterConvexPolygons++] = polygon;
    }

    // Сортировка - Хоар
    quickSortHoara(arrayPolygon, 0, counterConvexPolygons - 1);

    for(int indexPolygon = 0; indexPolygon < counterConvexPolygons; indexPolygon++) {
        writeFile << "#" << indexPolygon + 1 << ": ";
        writeFile << "P: " << arrayPolygon[indexPolygon].GetPerimetr() << " | S: " << arrayPolygon[indexPolygon].GetSquare() << "\t\t";
        
        counterConvexPoints = arrayPolygon[indexPolygon].GetCounterVertices();
        for(int indexPoint = 0; indexPoint < counterConvexPoints; indexPoint++) {
            writeFile << "(x:" << arrayPolygon[indexPolygon].GetX(indexPoint) << " | y:" << arrayPolygon[indexPolygon].GetY(indexPoint) << ")\t";
        }

        writeFile << std::endl;
    }

    readFile.close();
    writeFile.close();
}
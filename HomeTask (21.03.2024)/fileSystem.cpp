#include<iostream>
#include<fstream>

#include "fileSystem.h"
#include "Polygon.h"


void fileSystem(std::ifstream&readFile, std::ofstream&writeFile) {
    
    long double x, y, **array;
    unsigned int counterPolygon, counterPoints;
    readFile >> counterPolygon;

    Polygon **polygons = new Polygon*[counterPolygon];
    for(unsigned int indexPolygons = 0; indexPolygons < counterPolygon; indexPolygons++) {
        readFile >> counterPoints;

        for(unsigned int indexPoints = 0; indexPoints < counterPoints; indexPoints++) {
            readFile >> array[indexPoints][indexPoints % 2];
        }
    }

    for(unsigned int indexPolygon = 0; indexPolygon < counterPoints; indexPolygon++) {
        
    }

    writeFile << "" << std::endl;

    std::cout << "Write end" << std::endl;
}
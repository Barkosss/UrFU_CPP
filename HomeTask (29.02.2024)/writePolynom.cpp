#include <iostream>
#include <fstream>
#include <string>

#include "Polynom.h"

using std::string;

// Запись полиномов в файл
void writePolynom(std::ofstream&writeFile, Polynom*polynom) {
    
    try {
        string stringPolynom = "";
        int lengthPolynom = polynom->length;
        int* arrayPolynom = polynom->array;

        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            if (!arrayPolynom[indexFactor]) {
                continue;
            }
            // Представление многочленов
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }

        stringPolynom += std::to_string(arrayPolynom[indexFactor]);
        writeFile << stringPolynom << std::endl << std::endl;
    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}
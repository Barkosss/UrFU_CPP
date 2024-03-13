#include <iostream>
#include <fstream>
#include <string>

#include "Polynom.h"
#include "getFactorDiffer.h"

// Получить коэффициенты производной полинома
void getFactorDiffer(std::ofstream&writeFile, Polynom*polynoms, int counterPolynoms) {
    Polynom *resultPolynoms = new Polynom[counterPolynoms];
    int counterFactor, *arrayFactor;

    // Прохождение по многочленам -> Нахождение производной
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;
        int indexFactor = 1;
        for(; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor - 1] = polynoms[indexPolynom].array[indexFactor] * indexFactor;
        }

        resultPolynoms[indexPolynom].length = indexFactor - 1;
        resultPolynoms[indexPolynom].array = arrayFactor;
    }

    // ------ ЗАПИСЬ В ФАЙЛ ------

    std::string stringPolynom;
    int lengthPolynom, *arrayPolynom;

    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        stringPolynom = "";
        lengthPolynom = resultPolynoms[indexPolynom].length;
        arrayPolynom = resultPolynoms[indexPolynom].array;

        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Представление многочленов
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }

        stringPolynom += std::to_string(arrayPolynom[indexFactor]);
        writeFile << stringPolynom << std::endl << std::endl;
    }
}
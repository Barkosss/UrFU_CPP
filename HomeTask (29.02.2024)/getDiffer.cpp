#include <iostream>
#include <fstream>
#include <string>

#include "Polynom.h"
#include "getDiffer.h"
#include "degree.h"

// Получить производную полинома в точке
void getDiffer(std::ofstream&writeFile, Polynom*polynoms, int counterPolynoms, int intValue) {
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

    int resultDiffer;
    std::string stringPolynom;
    int lengthPolynom; int *arrayPolynom;
    // Прохождение по многочленам -> Нахождение значения в точке
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        resultDiffer = 0;
        stringPolynom = "";
        lengthPolynom = resultPolynoms[indexPolynom].length;
        arrayPolynom = resultPolynoms[indexPolynom].array;

        // Прохождение по коэффициентам многочлена
        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Результат
            resultDiffer += arrayPolynom[indexFactor] * degree(intValue, indexFactor);
            // Представление многочлена
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }
        
        // Повторяем действия для последнего, свободного, коэффициента
        resultDiffer += arrayPolynom[indexFactor];
        stringPolynom += std::to_string(arrayPolynom[indexFactor]);

        writeFile << "f'(" << intValue << ") = " << stringPolynom << " = " << resultDiffer << std::endl;
    }
}
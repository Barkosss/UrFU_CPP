#include <iostream>
#include <fstream>
#include <string>

#include "Polynom.h"
#include "degree.h"

using std::string;

// Получить значение в точке
void getValue(Polynom*polynoms, int counterPolynoms, int intValue, std::ofstream&writeFile) {
    
    int result;
    string stringPolynom;
    int lengthPolynom; int* arrayPolynom;
    // Проход по многочленам
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        result = 0;
        stringPolynom = "";
        lengthPolynom = polynoms[indexPolynom].length;
        arrayPolynom = polynoms[indexPolynom].array;

        // Проход по коэффициентам многочлена
        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Результат
            result += arrayPolynom[indexFactor] * degree(intValue, indexFactor);
            // Представление многочлена
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }
        
        // Повторяем действия для последнего, свободного, коэффициента
        result += arrayPolynom[indexFactor];
        stringPolynom += std::to_string(arrayPolynom[indexFactor]);

        writeFile << "f(" << intValue << ") = " << stringPolynom << " = " << result << std::endl;
    }

    writeFile << std::endl;
}
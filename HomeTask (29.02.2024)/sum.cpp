#include<iostream>
#include<cmath>

#include "sum.h"

// Сумма полиномов
Polynom sum(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxCounterFactor = 0, counterFactor;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        maxCounterFactor = std::max(polynoms[indexPolynom].length, maxCounterFactor);
    }

    // Массив с коэффициентами
    int *arrayFactor = new int[maxCounterFactor]{ 0 };

    // Складываем многочлены с массивом
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        // Пробегаемся по коэффициентам многочлена
        for(int indexFactor = 0; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor] += polynoms[indexPolynom].array[indexFactor];
        }
    }

    result.length = maxCounterFactor;
    result.array = arrayFactor;

    return result;
}
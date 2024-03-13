#include<iostream>
#include<cmath>

#include "sub.h"

// Разность полиномов
Polynom sub(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxCounterFactor = 0, counterFactor;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        maxCounterFactor = std::max(polynoms[indexPolynom].length, maxCounterFactor);
    }

    // Массив с коэффициентами
    int *arrayFactor = new int[maxCounterFactor]{ 0 };

    // Заполняем первый многочлен в массив
    int counterFactorOne = polynoms[0].length;
    for(int indexFactor = 0; indexFactor < counterFactorOne; indexFactor++) {
        arrayFactor[indexFactor] = polynoms[0].array[indexFactor];
    }

    // Вычитаем из результативного массива следующие многочлены
    for(int indexPolynom = 1; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        // Пробегаемся по коэффициентам многочлена
        for(int indexFactor = 0; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor] -= polynoms[indexPolynom].array[indexFactor];
        }
    }

    result.length = maxCounterFactor;
    result.array = arrayFactor;

    return result;
}
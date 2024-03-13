#include<iostream>
#include<cmath>

#include "multi.h"

using std::max;

// Произведение полиномов
Polynom multi(Polynom* polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxDegreePolynom = -1;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        
        for(int jndexPolynom = 0; jndexPolynom < counterPolynoms; jndexPolynom++) {
            if (indexPolynom == jndexPolynom) {
                continue;
            }

            maxDegreePolynom = max(maxDegreePolynom, polynoms[indexPolynom].length * polynoms[jndexPolynom].length);
        }
    }
    maxDegreePolynom--;

    int *arrayFactor = new int[maxDegreePolynom];

    // Заполняем нулями
    for(int indexFactor = 0; indexFactor < maxDegreePolynom; indexFactor++) {
        arrayFactor[indexFactor] = 0;
    }

    // Произведение первых двух
    for (int indexFactor = 0; indexFactor < polynoms[0].length; indexFactor++) {
		for (int jndexFactor = 0; jndexFactor < polynoms[1].length; jndexFactor++) {
			arrayFactor[indexFactor + jndexFactor] += polynoms[0].array[indexFactor] * polynoms[1].array[jndexFactor];
		}
	}

    // Находим произведение
    int counterFactor;
    for(int indexPolynom = 2; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        for (int indexFactor = 0; indexFactor < maxDegreePolynom; indexFactor++) {
            for (int jndexFactor = 0; jndexFactor < polynoms[indexPolynom].length; jndexFactor++) {
                arrayFactor[indexFactor + jndexFactor] += arrayFactor[indexFactor] * polynoms[indexPolynom].array[jndexFactor];
            }
        }
    }

    result.length = maxDegreePolynom;
    result.array = arrayFactor;
    
    return result;
}
#include<iostream>
#include<fstream>

#include "Rational.h"

int main() {

    std::ifstream readFile("test.txt");
    int counterOperations, counterRationals, numerator;
    unsigned denominator;
    readFile >> counterOperations;
    
    Rational **rationals = new Rational*[counterOperations];
    for(int indexOperator = 0; indexOperator < counterOperations; indexOperator++) {
        readFile >> counterRationals;
        rationals[indexOperator] = new Rational[counterRationals];
        
        for(int indexRational = 0; indexRational < counterRationals; indexRational++) {
            readFile >> numerator >> denominator;
            rationals[indexOperator][indexRational].updateNumerator(numerator);
            rationals[indexOperator][indexRational].updateDenominator(denominator);
        }
    }

    return 0;
}
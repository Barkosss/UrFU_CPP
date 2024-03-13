#include<iostream>
#include<fstream>

#include "Kramer.h"

void fileSystem(std::ifstream&readFile, std::ofstream&writeFile, int counter) {

    // Количество коэффициентов
    long double **factors = new long double*[counter];
    // Количество результатов многочленов
    long double *results = new long double[counter];

    // ------------ ЧТЕНИЕ ПОЛИНОМОВ ------------

    
    // Записываем элементы столбца в массив
    for(int index = 0; index < counter; index++) {
        factors[index] = new long double[counter];
        for(int jndex = 0; jndex < counter; jndex++) {
            readFile >> factors[index][jndex];
        }
        readFile >> results[index];
    }
    
    // ------------ ЧТЕНИЕ ПОЛИНОМОВ ------------

    // Результат вычислений
    long double* result = Kramer(factors, results, counter);
    
    // ------------ ЗАПИСЬ РЕЗУЛЬТАТОВ ------------

    writeFile << "RESULT:" << std::endl;
    for(int indexFactor = 0; indexFactor < counter; indexFactor++) {
        writeFile << "#X(" << indexFactor + 1 << "):\t" << result[indexFactor] << std::endl;
    }

    // ------------ ЗАПИСЬ РЕЗУЛЬТАТОВ ------------
}
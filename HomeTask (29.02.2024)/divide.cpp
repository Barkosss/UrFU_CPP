#include <iostream>

#include "Polynom.h"
#include "divide.h"

// Деление полиномов
Polynom divide(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Получаем количество коэффициентов первого многочлена
    int counterFactor = polynoms[0].length;
    // Создаем массив для хранения коэффициентов результирующего многочлена
    int* arrayFactor = new int[counterFactor + 1];

    // Выбираем первый многочлен в качестве делимого
    Polynom dividend = polynoms[0]; // Делимое

    // Перебираем остальные многочлены в качестве делителей
    for (int indexPolynom = 1; indexPolynom < counterPolynoms; indexPolynom++) {
        Polynom divisor = polynoms[indexPolynom]; // Делитель
        
        // Находим степень частного
        int quotientDegree = dividend.length - divisor.length + 1;
        
        // Коэффициенты частного
        int* quotientFactor = new int[quotientDegree];
        
        // Выполняем деление многочленов
        for (int indexFactor = 0; indexFactor < quotientDegree; indexFactor++) {
            // Вычисляем текущий коэффициент частного
            quotientFactor[indexFactor] = dividend.array[indexFactor] / divisor.array[0];
            
            // Вычисляем остаток от деления
            for (int jndexFactor = 0; jndexFactor < divisor.length; jndexFactor++) {
                dividend.array[indexFactor + jndexFactor] -= quotientFactor[indexFactor] * divisor.array[jndexFactor];
            }
        }
        
        // Освобождаем память изначального делимого
        delete[] dividend.array;
        
        // Обновляем делимое с новым остатком
        dividend.length = dividend.length - divisor.length + 1;
        dividend.array = quotientFactor;
    }

    // Заполняем ответ
    result.length = dividend.length;
    result.array = dividend.array;
    
    return result;
}
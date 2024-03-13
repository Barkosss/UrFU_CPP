#include<iostream>
#include<fstream>

#include "readPolynom.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

/*

---- data.txt ----
1 | Количество операций
2 | Количество многочленов | Количество операций | Сами операции...
3 | Многочлены... (От большей степени, к меньшей)
4 | Следующие многочлены...

*/

int main() {

    try {
        ifstream readFile("data.txt");
        ofstream writeFile("result.txt");

        int counterPolynoms;
        readFile >> counterPolynoms;

        for (int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
            readPolynom(readFile, writeFile);
        }

    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    return 0;
}

/*
7
2 1 sum --- Сумма
2 1 1
3 1 1 2
2 1 sub --- Разность
2 1 1
3 1 1 2
2 1 multi --- Производение
2 1 1
3 1 1 2
2 1 divide --- Деление
4 1 2 3 2
3 1 1 2
1 2 getValue 3 --- Получить значение в точке
3 1 3 2
1 2 getDiffer 2 --- Получить значение производной в точке
3 1 1 1
1 1 getFactorDiffer --- Получить коэффициенты производной
3 1 1 1
*/
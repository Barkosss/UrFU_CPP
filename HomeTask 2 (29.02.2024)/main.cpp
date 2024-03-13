#include<iostream>
#include<fstream>

#include "func.h"


/*

---- data.txt ----
1 | Количество операций
2 | Количество многочленов | Количество операций | Сами операции...
3 | Многочлены... (От большей степени, к меньшей)
4 | Следующие многочлены...

*/


int main() {

    std::ifstream readFile("data.txt");
    std::ofstream writeFile("result.txt");

    int counterPolynoms;
    readFile >> counterPolynoms;

    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        Polynom **polynoms = new Polynom*[counterPolynoms];
        readPolynom(readFile, writeFile, *polynoms);
    }

    return 0;
}
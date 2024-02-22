#include<iostream>
#include<fstream>

#include "matrix.h"

using std::endl;
using std::cout;
using std::ofstream;

void WriteMatrix(long sizeOfMatrix, long double **writeMatrix, long double sumMainDiagonal, ofstream&writeFile) {

    // Проверка на возможность открыть файл для чтения
    if (!writeFile.is_open()) {
        cout << "Error: Open file";
        return;
    }

    writeFile << "Sum: " << sumMainDiagonal << endl;
    for(int rows = 0; rows < sizeOfMatrix; rows++) {
        for(int collumns = 0; collumns < sizeOfMatrix; collumns++) {
            writeFile << writeMatrix[rows][collumns] << " ";
        }
        writeFile << endl;
    }
    writeFile << endl;

    cout << "Write files completed!" << endl;
    cout << "----------------------" << endl;
}
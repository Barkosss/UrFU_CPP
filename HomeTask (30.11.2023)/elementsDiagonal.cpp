#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int main() {

    int lenMatrix;
    cout << "Enter length matrix: "; cin >> lenMatrix;
    if (lenMatrix < 1) { cout << "The length of the matrix must be greater than 0!" << endl; return 0; };

    int **matrix = new int*[lenMatrix];
    for(int i = 0; i < lenMatrix; i++) {
        matrix[i] = new int[lenMatrix];
        cout << i + 1 << ". Row: ";
        for(int j = 0; j < lenMatrix; j++) cin >> matrix[i][j];
    }
    cout << endl;

    cout << "View matrix:" << endl;
    for(int i = 0; i < lenMatrix; i++) {
        for(int j = 0; j < lenMatrix; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // minNumber - выше диагонила, maxNumber - ниже диагонали
    int upDiagonal = 10'000'000, downDiagonal = -10'000'000;
    for(int i = 0; i < lenMatrix; i++) {

        // Поиск минимального элемента выше диагонали
        for(int j = i + 1; j < lenMatrix; j++) {
            upDiagonal = min(upDiagonal, matrix[i][j]);
        }

        // Поиск максимального элемента ниже диагонали
        for(int j = 0; j < i; j++) {
            downDiagonal = max(downDiagonal, matrix[i][j]);
        }
    }

    if (upDiagonal >= downDiagonal) cout << "True | The condition is completed!" << endl;
    else cout << "False | Condition not completed!" << endl;

    return 0;
}
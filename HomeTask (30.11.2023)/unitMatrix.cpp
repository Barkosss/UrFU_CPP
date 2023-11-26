#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    int lenMatrix;
    cout << "Enter length matrix: "; cin >> lenMatrix;
    if (lenMatrix < 1) {
        cout << "The length of the matrix must be greater than 0!" << endl;
        return 0;
    }

    int **matrix = new int*[lenMatrix];

    for(int i = 0; i < lenMatrix; i++) {
        matrix[i] = new int[lenMatrix]{0};
        for(int j = 0; j < lenMatrix; j++) if (i == j) matrix[i][j] = 1;
    }
    cout << endl;

    cout << "View matrix:" << endl;
    for(int i = 0; i < lenMatrix; i++) {
        for(int j = 0; j < lenMatrix; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
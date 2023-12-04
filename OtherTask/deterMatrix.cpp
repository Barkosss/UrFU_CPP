#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

/*
Нахождение определителя у матрицы
матрицу читаем с файла
*/


int CreateMatrix(int **matrix,  int lenMatrix) {

}

int sum;
int GetDeterminantOfMatrix(int **matrix, int lenMatrix) {
    if (lenMatrix == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    sum = 0;
    for(int i = 0; i < lenMatrix; i++) {
        sum += matrix[0][i];
        // Доделать
    }
    return;
}

int main() {
    ifstream file ("matrix.txt");
    if (!file) return;
    int lenMatrix; file >> lenMatrix;
    int **matrix = new int*[lenMatrix];
    for(int i = 0; i < lenMatrix; i++) {
        matrix[i] = new int[lenMatrix];
        for(int j = 0; j < lenMatrix; j++) file >> matrix[i][j];
    }
    cout << GetDeterminantOfMatrix(matrix, lenMatrix);
    return 0;
}
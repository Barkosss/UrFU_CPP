#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int main() {

    int collumns, rows;
    cout << "Enter counter collumns: "; cin >> collumns;
    if (collumns < 1) { cout << "" << endl; return 0; }
    cout << "Enter counter rows: "; cin >> rows;
    if (rows < 1 || collumns < 1) { cout << "The counter rows and collumns must be greater than 0" << endl; return 0; }

    cout << "Create matrix:" << endl;
    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[collumns];
        cout << i + 1 << ". Row: ";
        for(int j = 0; j < collumns; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << endl;

    cout << "View matrix" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < collumns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int maxNumberRow, minNumberCollumn; 
    cout << "Answer:" << endl; int number; int count = 0;
    for(int indexRow = 0; indexRow < rows; indexRow++) {
        for(int indexCollumn = 0; indexCollumn < collumns; indexCollumn++) {
            // ПРОБЛЕМА
            minNumberCollumn = 10'000'000; maxNumberRow = -10'000'000;
            number = matrix[indexRow][indexCollumn];

            for(int row = 0; row < rows; row++) maxNumberRow = max(number, matrix[row][indexCollumn]);
            for(int collumn = 0; collumn < collumns; collumn++) minNumberCollumn = min(number, matrix[indexRow][collumn]);

            if (number == maxNumberRow && number == minNumberCollumn) {
                cout << count + 1 << ". Row: " << indexRow << ", Collumn: " << indexCollumn << endl;
                count++;
            }
            // ПРОБЛЕМА
        }
    }

    if (!count) cout << "There is no solution for this matrix!" << endl;

    return 0;
}
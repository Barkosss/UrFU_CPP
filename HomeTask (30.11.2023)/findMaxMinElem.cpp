#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int main() {


    int rows, collumns; // rows - строки, collumns - столбцы
    cout << "Enter counter collumns: "; cin >> collumns; // Пользователь указывает количество стобцов
    cout << "Enter counter rows: "; cin >> rows; // Пользователь указывает количество строк
    if (rows < 1 || collumns < 1) { cout << "The counter rows and collumns must be greater than 0." << endl; return 0; };

    cout << "Create Matrix" << endl;
    // Создаём массив с кол-вом колонок равное collumns
    int **matrix = new int*[collumns];
    // Создаём ещё один массив в столбце (collumn)
    for(int collumn = 0; collumn < collumns; collumn++) matrix[collumn] = new int[rows];
    for(int row = 0; row < rows; row++) { // Запись значений в массива
        cout << row + 1 << ". Row: ";
        for(int collumn = 0; collumn < collumns; collumn++) {
            cin >> matrix[collumn][row];
        }
    }
    cout << endl;

    cout << "Vew Matrix" << endl;
    for(int row = 0; row < rows; row++) {
        for(int collumn = 0; collumn < collumns; collumn++) {
            cout << matrix[collumn][row] << " ";
        }
        cout << endl;
    }
    cout << endl;


    int maxNumberRow, minNumberCollumn; 
    cout << "Answer:" << endl; int number; int count = 0;
    
    for(int collumn = 0; collumn < collumns; collumn++) {
        for(int row = 0; row < rows; row++) {
            maxNumberRow = -1 * INT_MAX - 1; minNumberCollumn = INT_MAX;
            number = matrix[collumn][row];

            // Минимальное число в столбце
            for(int rowInCollumn = 0; rowInCollumn < rows; rowInCollumn++) 
                minNumberCollumn = min(minNumberCollumn, min(number, matrix[collumn][rowInCollumn]));

            // Максимальное число в строке
            for(int collumnInRow = 0; collumnInRow < collumns; collumnInRow++)
                maxNumberRow = max(maxNumberRow, max(number, matrix[collumnInRow][row]));


            if (number == maxNumberRow && number == minNumberCollumn) {
                cout << count + 1 << ". Row: " << row << ", Collumn: " << collumn << endl;
                count++;
            }
        }
    }

    if (!count) cout << "There is no solution for this matrix!" << endl;

    return 0;
}
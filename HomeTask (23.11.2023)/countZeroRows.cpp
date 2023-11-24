#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void main() {

	int n;
	cout << "Enter counter rows in matrix: "; cin >> n;
	int m;
	cout << "Enter counter collums in matrix: "; cin >> m;

	double long** matrix = new double long*[n];

	// Ввод матрицы
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". Row: ";
		matrix[i] = new double long[m];
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	// Ввод матрицы


	// Проверка матрицы
	int count = 0, countZero;
	for (int i = 0; i < n; i++) {
		countZero = 0;
		for (int j = 0; j < m; j++) {
			if (!matrix[i][j]) countZero++;
		}

		if (countZero == m) count++;
	}
	// Проверка матрицы
	

	// Вывод матрицы в консоль
	cout << endl << endl;
	cout << "Matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	// Вывод матрицы в консоль


	// Результат
	cout << endl;
	cout << "Result: " << count << endl;
}
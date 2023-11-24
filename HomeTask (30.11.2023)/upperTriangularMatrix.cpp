#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void main() {

	int n;
	cout << "Enter length matrix: "; cin >> n;

	double long** matrix = new double long*[n];

	// Создание матрицы
	for (int i = 0; i < n; i++) {
		matrix[i]  = new double long[n];
		cout << i + 1 << " row: ";
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	// Создание матрицы


	// Вывод самой матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	// Вывод самой матрицы


	// Проверка матрицы
	int count = 0; int counter; int j;
	for (int i = 1; i < n; i++) {
		counter = 0; j = 0;
		for (; j < i; j++) {
			if (!matrix[i][j]) counter++;
		}

		if (counter == j) count++;
	}
	// Проверка матрицы

	if (count == n - 1) cout << "Yes, the matrix is upper-triangular" << endl;
	else cout << "No, the matrix is not upper-triangular" << endl;
}
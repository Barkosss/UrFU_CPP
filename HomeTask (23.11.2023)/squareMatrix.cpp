#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void main() {
	int n;
	cout << "Enter n: "; cin >> n;

	int** matrix = new int* [n];

	cout << endl;
	cout << "--- CREATE MATRIX ---" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". Row: ";
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
	cout << endl;
	cout << "---VIEW MATRIX---" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int count = 0;
	long sum = 0; bool bFlag = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) continue;
			sum += abs(matrix[i][j]) + abs(matrix[j][i]);
		}

		if (matrix[i][i] > sum) {
			bFlag = true;
		}

		if (matrix[i][i] >= sum) count++;
	}

	if (count == n && bFlag) {
		cout << "The matrix has the property (True)" << endl;
	}
	else {
		cout << "The matrix does not have the property (False)" << endl;
	}
}
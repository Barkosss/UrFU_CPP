#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int main() {

	int n1;
	cout << "Length counter rows in one matrix: "; cin >> n1;
	int m1;
	cout << "Length counter collums in one matrix: "; cin >> m1;

	int n2;
	cout << "Length counter rows in two matrix: "; cin >> n2;
	int m2;
	cout << "Length counter collums in two matrix: "; cin >> m2;

	int n = min(n1, n2);
	int m = min(m1, m2);

	if (m1 != m2 || n1 != n2) {
		cout << endl << "The dimension of the matrix must be the same" << endl;
		return 0;
	}

	int** matrixOne = new int* [n1];
	int** matrixTwo = new int* [n2];
	int** sumMatrix = new int* [n];

	cout << endl;
	cout << "One matrix:" << endl;
	for (int i = 0; i < n1; i++) {
		cout << i + 1 << ". Row: ";
		matrixOne[i] = new int[m1];
		for (int j = 0; j < m1; j++) {
			cin >> matrixOne[i][j];
		}
	}

	cout << endl << endl;
	cout << "Two matrix:" << endl;
	for (int i = 0; i < n2; i++) {
		cout << i + 1 << ". Row: ";
		matrixTwo[i] = new int[m2];
		for (int j = 0; j < m2; j++) {
			cin >> matrixTwo[i][j];
		}
	}

	cout << endl << endl;
	cout << "One matrix:" << endl;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			cout << matrixOne[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "Two matrix:" << endl;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			cout << matrixTwo[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "Result:" << endl;
	for (int i = 0; i < n; i++) {
		sumMatrix[i] = new int[m];
		for (int j = 0; j < m; j++) {
			sumMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
			cout << sumMatrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
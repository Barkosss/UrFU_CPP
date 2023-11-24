#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void main() {
	int n;
	cout << "Enter length matrix: "; cin >> n;

	int* matrix = new int[n - 1];
	for (int i = 1; i < n; i++) matrix[i - 1] = i;

	cout << endl;
	cout << "Result:" << endl;
	
	for (int i = 1; i < n; i++) cout << matrix[i - 1] << " ";
	cout << endl;
	for (int i = 1; i < n - 1; i++) {
		for (int j = n - i - 1; j < n - 1; j++) {
			cout << matrix[j] << " ";
		}
		for (int j = 0; j < n - i - 1; j++) {
			cout << matrix[j] << " ";
		}
		cout << endl;
	}
}
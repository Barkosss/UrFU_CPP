#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int Pascal(int row, int coll) {
	if (coll == 0 || coll == row) return 1;
	return Pascal(row - 1, coll - 1) + Pascal(row - 1, coll);
}

void main() {

	int number; // Номер строки
	cout << "Enter n row(-s): "; cin >> number;
	if (number < 0) { // Если указан отрицательный номер строки
		cout << "The line number must be greater than or equal to 0"; return;
	}
	for (int i = 0; i <= number; i++) cout << Pascal(number, i) << " ";
}
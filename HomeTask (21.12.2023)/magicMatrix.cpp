#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

// Задание: #1

int main() {
	int number, count;
	int x, y, i1, j1;
	
	cout << "Enter counter matrix: "; cin >> count;

	std::ofstream writeFile;
	writeFile.open("magicMatrix.txt");

	for (int i = 0; i < count; i++) {
        cout << "Enter odd n: "; cin >> number;
        while(number % 2 == 0) { cout << "No. Enter odd n: "; cin >> number; };
        int** matrix = new int*[number];
        for(int j = 0; j < number; j++) matrix[j] = new int[number];
		x = 0;
		y = number / 2;
		matrix[x][y] = 1;
		for (int j = 2; j <= number * number; j++) {
			i1 = x - 1;
			j1 = y + 1;
			if (j1 > number - 1) j1 = 0;
			if (i1 < 0) i1 = number - 1;
			if (matrix[i1][j1]) {
				i1 = x + 1;
				j1 = y;
			}
			matrix[i1][j1] = j;
			x = i1;
			y = j1;
		}
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				cout << matrix[i][j] << "\t";
				writeFile << matrix[i][j] << "\t";
			}
			cout << endl;
			writeFile << endl;
		}
		writeFile << endl;
		for (int j = 0; j < number; j++) delete matrix[j];
        delete matrix;
	}

	writeFile.close();
	return 0;
}
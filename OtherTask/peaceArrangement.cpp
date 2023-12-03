#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::min;

/*
0 - Место свободно
1 - Место занято ферзём
*/

int countSolution = 0;
bool newRowQueen = false;
int count = 1;


// Вывод расстановки
void static PrintSolution(int* queens, int** field, int number) {

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (field[i][j]) cout << 'q';
			else cout << '-';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < number; i++) cout << '=';
	cout << endl;
	return;
}


// Проверка на то, что можно поставить в выбранной ячейке ферзя
bool static CheckSetQueen(int** field, int x, int y, int number) {

	// Вертикаль
	for (int row = 0; row < number; row++) {
		if (field[x][row]) return false;
	}

	// Горизонталь
	for (int col = 0; col < number; col++) {
		if (field[col][y]) return false;
	}

	// Главная диагональ
	for (int i = 0; i < number; i++) {
		if (field[i][abs(x - y) + i]) return false;
	}

	// Обратная диагональ
	int stop = min(x + y, number);
	for (int i = 0; i < stop; i++) {
		if (field[abs(x + y) - i][i]) return false;
	}

	return true;
}

// Функция для установки ферзя (X - столбец, Y - строка)
void static SetQueens(int* queens, int** field, int number, int x, int y) {

	// Если выходим за пределы по Y
	if (y + 1 > number) {
		if (!newRowQueen) { // Если обнуление номера строки не было
			newRowQueen = true;
			return SetQueens(queens, field, number, x, 0);
		}

		// Если было обнуление
		int oldQueenY = queens[x - 1];
		queens[x - 1] = -1;
		newRowQueen = false;
		return SetQueens(queens, field, number, x - 1, y + 1);
	}

	// Если количество решение больше или равно чем number
	if (countSolution == number) {
		cout << "Exit" << endl;
		return;
	}

	else if (count == number) {
		PrintSolution(queens, field, number);
		countSolution++;
		field[x][y] = 0; // Убираем текущего ферзя
		queens[x] = -1;
		return SetQueens(queens, field, number, x, y + 1);
	}

	bool findCeil = false;
	for(int row = y; row < number; row++) {
		if (!field[x][row] && CheckSetQueen(field, x, row, number)) {
			field[x][row] = 1; // Ставим ферзя на место
			queens[x] = row;
			count++;
			return SetQueens(queens, field, number, x + 1, y + 2);
		}
	}

	if (!findCeil) { // Если не была найдена свободная ячейка
		field[x - 1][queens[x - 1]] = 0;
		queens[x - 1] = -1;
		return SetQueens(queens, field, number, x - 1, queens[x - 1] + 1);
	}
}

int main() {

	int number;
	cout << "Enter number: "; cin >> number;
	if (number < 4) {
		cout << "Number < 4" << endl;
		return 0;
	}
	int* queens = new int[number] { -1 }; // Координаты установленных ферзей (По умолчанию -1)
	int** field = new int* [number]; // Поле NxN
	for (int i = 0; i < number; i++) field[i] = new int[number] { 0 }; // Создание массива в массиве
	SetQueens(queens, field, number, 0, 0); // Вызов функции
	cout << "Return 0;" << endl;
	return 0;
}
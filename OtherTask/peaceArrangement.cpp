#include<iostream>

using std::cin;
using std::cout;
using std::endl;

/*
0 - Место свободно
1 - Место занято ходом ферзя
2 - Место занято ферзём
*/

int countSolution = 0;
int count = 1;

// Вывод расстановки
void static PrintSolution(int* queens, int**field, int number) {
    
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (field[i][j] == 2) cout << 'q';
			else cout << '-';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < number; i++) cout << '=';
	cout << endl;

    return;
}

// Функция для расставноки ходов ферзя
void static SetMoveQueens(int** field, int x, int y, int number) {
    //cout << "SetMoveQueens: Start" << endl;
	// Горизонтально и Вертикально
	for (int i = 0; i < number; i++) {
		if (field[x][i] == 2 || field[i][x]) continue;
		field[x][i] = 1;
		field[i][x] = 1;
	}


	// Правые диагонали
	for (int i = x + 1; i < number; i++) {
		for (int j = x + 1; j < number; j++) {
			field[i][j] = 1;

		}
	}
	for (int i = x - 1; i < number; i++) {
		for (int j = x - 1; j > 0; j--) {
			field[i][j] = 1;
		}
	}

	// Левые диагонали
	for (int i = x - 1; i > 0; i--) {
		for (int j = x + 1; j < number; j++) {
			field[i][j] = 1;

		}
	}
	for (int i = x - 1; i > 0; i--) {
		for (int j = x - 1; j > 0; j--) {
			field[i][j] = 1;
		}
	}

    return;
}


// Функция для установки ферзя (X - столбец, Y - строка)
void static SetQueens(int* queens, int** field, int number, int x, int y) {


	/*
	Если X = 0 & Y = 0:
		То пробегаемся по полю и если находим 0 в ячейку, то ставим туда 2 (ферзя). Вызываем функцию, которая расставит пути ферзя

	Если X = number & Y = number
		Вызываем поле и последнего ферзя поднимаем наверх

	В начале мы пробегаем по столбцу и ишем пустую ячейку в поле.
	Если мы её находим, то туда ставим ферзя и расставляем его возможные хотя (ставим 1).
	Если мы её не находим, то возращаемся к прошлому ферзю и сдвигаем его по y вверх
	И так далее...
	*/

	// Если X или Y вышли за пределы поля
	if (x > number || y > number) {
		return SetQueens(queens, field, number, x - 1, 0);
	}

	// Если количество решение больше или равно чем number^2
	if (countSolution >= number * number) {
		cout << "Exit" << endl;
		return;
	}

	// Если мы дошли до конца поля
	else if (x == number && y == number) {
		PrintSolution(queens, field, number);
		countSolution++;
		x = 0; y = y + 1;
		return SetQueens(queens, field, number, x, y);
	}

	bool findCeil = false;
	for(int col = x; col < number; col++) {
		for(int row = y; row < number; row++) {
			if (!field[col][row]) {
				field[col][row] = 2; // Ставим ферзя на место
				findCeil = true; // Метка о том, что нашли свободную ячейку

				SetMoveQueens(field, col, row, number); // Расстановка ходов у ферзя
				return SetQueens(queens, field, number, x + 1, 0);
			}
		}
	}

	if (!findCeil) { // Если не была найдена свободная ячейка
		return SetQueens(queens, field, number, x-1, queens[x - 1] + 1);
	}
}

int main() {		

	int number;
	cout << "Enter number: "; cin >> number;

	int* queens = new int[number] { -1 };
	int** field = new int*[number] { 0 };
	for (int i = 0; i < number; i++) field[i] = new int[number]{ 0 };
	SetQueens(queens, field, number, 0, 0);
    cout << "Return 0;" << endl;
	return 0;
}
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

// Высчитывание угла
double long CalcAngle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y) {

	double vector1X = point1X - point2X;
	double vector1Y = point1Y - point2Y;
	double vector2X = point3X - point2X;
	double vector2Y = point3Y - point2Y;

	double dotProduct = vector1X * vector2X + vector1Y * vector2Y;
	double magnitude1 = sqrt(vector1X * vector1X + vector1Y * vector1Y);
	double magnitude2 = sqrt(vector2X * vector2X + vector2Y * vector2Y);

	double angle = acos(dotProduct / (magnitude1 * magnitude2));
	return angle;
}


// Функция для наибольшего угла между трёх точек
void SearchLargestAngleTriangle(double **arr, int count) {
	double long maxAngle = 0.0;
	double long onePoint[] = { 0, 0 };
	double long twoPoint[] = { 0, 0 };
	double long threePoint[] = { 0, 0 };

	double long angle;
	for (int i = 0; i < count - 2; i++) {
		for (int j = i + 1; j < count - 1; j++) {
			for (int k = j + 1; k < count; k++) {
				angle = CalcAngle(arr[i][0], arr[i][1], arr[j][0], arr[j][1], arr[k][0], arr[k][1]);
				if (angle > maxAngle) {
					maxAngle = angle;
					onePoint[0] = arr[i][0]; onePoint[1] = arr[i][1];
					twoPoint[0] = arr[j][0]; twoPoint[1] = arr[j][1];
					threePoint[0] = arr[k][0]; threePoint[1] = arr[k][1];
				}
			}
		}
	}

	cout << "Triangle with max angle: (" << onePoint[0] << ", " << onePoint[1] << "), (" << twoPoint[0] << ", " << twoPoint[1] << "), (" << threePoint[0] << ", " << threePoint[1] << ")" << endl;
}

// Основная функция
void main() {

	int count;
	cout << "Enter counter dots (>= 3): "; cin >> count; // Укаазать кол-во точек;
	if (count < 3) {
		cout << "The number of points must be greater than or equal to 3!" << endl;
		return;
	}
	double **arr = new double*[count];

	// Добавляем в массив arr ещё один массив, которых хранит только 2 элемента (X, Y);
	for (int i = 0; i < count; i++) arr[i] = new double[2];

	for (int i = 0; i < count; i++) { // Пользователь указывает координаты точке;
		cout << i + 1 << " dot: " << endl;
		cout << "X: "; cin >> arr[i][0];
		cout << "Y: "; cin >> arr[i][1];
		cout << endl;
	}

	SearchLargestAngleTriangle(arr, count);
}
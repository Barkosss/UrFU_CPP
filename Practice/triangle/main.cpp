#include <iostream>

#include "Point.h"
#include "squarePoint.h"
#include "getSquare.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int counterPoints;
    cout << "Enter counter points: ";
    cin >> counterPoints;

    Point *points = new Point[counterPoints];
    double x, y;
    int indexPoint = 0; Point point;
    cout << "----- INPUT -----" << endl;
    for(; indexPoint < counterPoints;) {
        cout << "#" << indexPoint << ": X = ";
        cin >> x;
        cout << "#" << indexPoint << ": Y = ";
        cin >> y;

        point.x = x;
        point.y = y;
        ////cout << "Debug | " << "X:" << x << " Y:" << y << endl;

        // Отсекаем отрицательные x и y
        if (x >= 0 && y >= 0) {
            points[indexPoint++] = point;
        }
    }
    cout << "----- INPUT -----" << endl;
    cout << endl;
    // Обновляем количество точек
    counterPoints = indexPoint;

    // Ошибка: Недостаточно точек
    if (counterPoints < 3) {
        //cout << "Error: " << endl;
        return 1;
    }

    // Нахождение треугольников
    squarePoint *squarePoints = new squarePoint[counterPoints];
    int indexSquarePoints = 0; long double result;
    for(int indexOnePoint = 0; indexOnePoint < counterPoints; indexOnePoint++) {
        for(int indexTwoPoint = 0; indexTwoPoint < counterPoints; indexTwoPoint++) {
            for(int indexThreePoint = 0; indexThreePoint < counterPoints; indexThreePoint++) {
                if (indexOnePoint == indexTwoPoint || indexOnePoint == indexThreePoint || indexTwoPoint == indexThreePoint) {
                    continue;
                }

                //cout << "Start" << endl;
                result = getSquare(points[indexOnePoint], points[indexTwoPoint], points[indexThreePoint]);
                //cout << "End" << endl;

                //cout << "Start write" << endl;
                squarePoints[indexSquarePoints].oneX = points[indexOnePoint].x;
                //cout << "1x: " << points[indexOnePoint].x << endl;
                squarePoints[indexSquarePoints].oneY = points[indexOnePoint].y;
                //cout << "1y: " << points[indexOnePoint].y << endl;
                squarePoints[indexSquarePoints].twoX = points[indexTwoPoint].x;
                //cout << "2x: " << points[indexTwoPoint].x << endl;
                squarePoints[indexSquarePoints].twoY = points[indexTwoPoint].y;
                //cout << "2y: " << points[indexTwoPoint].y << endl;
                squarePoints[indexSquarePoints].threeX = points[indexThreePoint].x;
                //cout << "3x: " << points[indexThreePoint].x << endl;
                squarePoints[indexSquarePoints].threeY = points[indexThreePoint].y;
                //cout << "3y: " << points[indexThreePoint].y << endl;
                squarePoints[indexSquarePoints].square = result;
                //cout << "sq: " << result << endl;
                //cout << "End write" << endl;
                
                //cout << "#" << indexSquarePoints << endl;
                indexSquarePoints++;
            }
        }
    }

    // Сортировка
    squarePoint temp;
    for(int jndex = indexSquarePoints - 1; jndex > 0; jndex--) {
        for(int index = 0; index < jndex; index++) {
            if (squarePoints[index].square > squarePoints[index + 1].square) {
                temp = squarePoints[index];
                squarePoints[index] = squarePoints[index + 1];
                squarePoints[index + 1] = temp;
            }
        }
    }

    // Вывод
    cout << "----- OUTPUT -----" << endl;
    for(int indexSquare = 0; indexSquare < indexSquarePoints; indexSquare++) {
        cout << "#" << indexSquare << ": | (" << squarePoints[indexSquare].oneX << ", " << squarePoints[indexSquare].oneY << ") | ";
        cout << "(" << squarePoints[indexSquare].twoX << ", " << squarePoints[indexSquare].twoY << ") | ";
        cout << "(" << squarePoints[indexSquare].threeX << ", " << squarePoints[indexSquare].threeY << ") = ";
        cout << squarePoints[indexSquare].square << endl;
    }
    cout << "----- OUTPUT -----" << endl;

    return 0;
}
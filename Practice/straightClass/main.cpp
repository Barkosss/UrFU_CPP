#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include "straight.h"

void parall(long double a1, long double a2, long double b1, long double b2)
{
    if ((a1 / a2) == (b1 / b2))
    {
        cout << "Lines parallel!";
        system("pause");
        exit(0);
    }
}
void intersect(long double a1, long double a2, long double b1, long double b2, long double c1, long double c2, long double& x, long double& y)
{
    long double det = a1 * b2 - a2 * b1;
    x = (b1 * c2 - b2 * c1) / det;
    y = (a2 * c1 - a1 * c2) / det;
}

int main() {
    long double a1, a2, b1, b2, c1, c2;
    long double x, y, x1, y1, x2, y2, x3, y3, x4, y4;
    int counterStraight, pointX, pointY;

    // Количество прямых
    cout << "Enter counter straight: ";
    cin >> counterStraight;

    Straight **straights = new Straight*[counterStraight];
    for(int indexStraight = 0; indexStraight < counterStraight; indexStraight++) {
        cout << "Enter X: "; cin >> pointX;
        cout << "Enter Y: "; cin >> pointY;
        straights[indexStraight] = new Straight(pointX, pointY);
    }

    for(int indexStraight = 0; indexStraight < counterStraight - 1; indexStraight++) {
        a1 = y1 - y2;
        b1 = x2 - x1;
        c1 = x1 * y2 - x2 * y1;
        a2 = y3 - y4;
        b2 = x4 - x3;
        c2 = x3 * y4 - x4 * y3;
    
        parall(a1, a2, b1, b2);
    
        intersect(a1, a2, b1, b2, c1, c2, x, y);
        cout << "Point of intersection: X = " << x << " Y = " << y << endl;
    }

    return 0;
}
#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "----- SIMPLE NUMBER -----" << endl;

    int userNumber;
    cout << "Enter number: "; cin >> userNumber;

    int number = 2; int squareNumber = pow(userNumber, 0.5);
    for(; number <= squareNumber; number++) {
        if (userNumber % number == 0) break;
    }

    if (number != squareNumber) cout << "True | Number " << userNumber << " is simple!" << endl;
    else cout << "False | Number " << userNumber << " is not simple!" << endl;

    return 0;
}
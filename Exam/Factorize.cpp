#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

int* Factorize(int number, int& counter) {
    int squareNumber = sqrt(number);
    int* primes = new int[squareNumber]{ 0 };
    int k = 0;

    for(int i = 2; i <= squareNumber; i++) {
        while(number % i == 0) {
            primes[k++] = i;
            number /= i;
        }
    }

    if (number != 1) {
        primes[k++] = number;
    }

    counter = k;
    return primes;
}

int main() {
    cout << "----- FACTORIZATION -----" << endl;

    int number;
    cout << "Enter number for factorization: "; cin >> number;

    int counterElementOfArray;
    int* array = Factorize(number, counterElementOfArray);

    cout << number << " = ";
    int index = 0;
    for(; index < counterElementOfArray - 1; index++) {
        cout << array[index] << " * ";
    }
    cout << array[index];

    return 0;
}
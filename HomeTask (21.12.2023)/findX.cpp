#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int lenArray;
    cout << "Enter len array: "; cin >> lenArray;
    int *array = new int[lenArray];

    cout << "Create array:" << endl;
    for(int i = 0; i < lenArray; i++) cin >> array[i];

    

    return 0;
}
#include<iostream>

using std::cin; using std::cout; using std::endl;

void main() {

	int lenArray;
	cout << "Specify the length of the array: "; cin >> lenArray;
	if (lenArray < 1) {
		cout << "The length of the array must be greater than 0!"; return;
	}

	int* arr = new int(lenArray + 1);
	for (int i = 0; i < lenArray; i++) { cout << i + 1 << ". Elements: "; cin >> arr[i]; }


}
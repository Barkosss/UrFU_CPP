#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned num;
    cin >> num;

    int *arr = new int[num];

    for(int index = 0; index < num; index++) {
        cin >> arr[index];
    }
    unsigned limit = 1 << num;
    for(unsigned index = 1; index < limit; index++) {
        for(int jndex = 0; jndex < num; jndex++) {
            if (index & (1 << jndex)) {
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
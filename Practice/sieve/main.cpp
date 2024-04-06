#include<iostream>

bool Simple() {

}

int main() {
    int num;
    std::cin >> num;
    int *arr = new int[num / sizeof(int) + 1]{ 0 };
    arr[0] = 3;

    for(int index = 2; index < sizeof(int); index++) {
        if (arr[index >> 5] & 1 << index % sizeof(int)) {
            continue;
        }

        for(int jndex = 2; jndex < num; jndex += index) {
            arr[jndex >> 5] |= 1 << jndex % sizeof(int);
        }
        std::cout << index << std::endl;
    }

    return 0;
}
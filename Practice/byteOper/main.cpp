#include<iostream>
#include<fstream>


// Цифры
short Compate(int num) {
    short arr = 0;
    while(num) {
        arr = arr | (1 << (num % 10));
        num /= 10;
    }

    return arr;
}

// Вывод
void print(short arr) {

    for(int i = 0; i < 10; i++) {
        if (arr & 1 << i) {
            std::cout << i;
        }
        arr >> 1;
    }
}

int main() {
    std::ifstream readFile("nums.txt");
    int numA, numB;
    short arrA, arrB;

    while(!readFile.eof()) {
        readFile >> numA >> numB;
        arrA = Compate(numA);
        arrB = Compate(numB);

        // Вывод
        std::cout << "Arr A(" << numA << "): "; print(arrA); std::cout << std::endl;
        std::cout << "Arr B(" << numB << "): "; print(arrB); std::cout << std::endl;
        std::cout << "A & B: "; print(arrA & arrB); std::cout << std::endl;
        std::cout << "A | B: "; print(arrA | arrB); std::cout << std::endl;
        std::cout << "A П B"; print(arrA ^ arrA & arrB); std::cout << std::endl;
        std::cout << "A O B"; print(arrB ^ arrA & arrB); std::cout << std::endl;

    }

    return 0;
}
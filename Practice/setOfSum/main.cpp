#include<iostream>
#include<fstream>


/* Результаты:
-1 = Количество меньше нужного
0 = Нужное количество
1 = Количество больше нужного
*/
unsigned char checkCounterDigits(unsigned long number, unsigned long findCounterDigits) {
    unsigned long counterDigits = 0;
    while(number) {
        counterDigits++;
        number /= 10;
    }
    return ((counterDigits == findCounterDigits) ? (0) : ((counterDigits > findCounterDigits) ? (1) : (-1)));
}


int main() {
    unsigned long findCounterDigits;
    std::cout << "Enter counter digits: ";
    std::cin >> findCounterDigits;

    std::ifstream readFile("read.txt");

    unsigned long counterNumbers;
    readFile >> counterNumbers;

    unsigned long long size = sizeof(unsigned long long);
    unsigned long long array = 0;
    unsigned long number;
    for(unsigned long indexNumber = 0; indexNumber < counterNumbers; indexNumber++) {
        readFile >> number;
        array |= 1 << number;
    }
    readFile.close();

    std::ofstream writeFile("result.txt");
    unsigned long currSum = 0, tempSum = 0;
    while(true) {
        
        for(unsigned long index = 0; index < size; index++) {
            if (!(array & (1 << index))) continue;

            tempSum += index;

            if (checkCounterDigits(tempSum, findCounterDigits) == '1') {
                // ...
            } else if (checkCounterDigits(tempSum, findCounterDigits) == '0') {
                // ...
            } else {
                // ...
            }
        }
    }

    writeFile.close();
    return 0;
}
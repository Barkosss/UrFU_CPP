#include<iostream>

/*
В массиве из N целых чисел найти все k-элементные 
подмножества, состоящие из попарно взаимно простых
чисел.
*/

unsigned counterNums, counterElements;
unsigned indexSubSet;

int gcd(int a, int b) {
    if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

void Compute(int* arr) {
    int mask = 0;

    // Перебор всех подмножеств
    for(unsigned index = 0; index < (1 << counterNums); index++) {
        indexSubSet = 0;
        int* subset = new int[counterElements];
        for(unsigned jndex = 0; jndex < counterNums; jndex++) {
            if (index & (1 << jndex)) {
                subset[indexSubSet] = arr[jndex];
            }
        }

        bool isCoprime = true;
        for(unsigned kndex = 0; kndex < counterElements; kndex++) {
            for(unsigned lndex = kndex + 1; lndex < counterElements; lndex++) {
                if (!gcd(subset[kndex], subset[lndex])) {
                    isCoprime = false;
                    break;
                }
            }
        }

        //
    }
}


/*

// Функция для проверки взаимной простоты двух чисел
bool isCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

// Функция для перебора всех подмножеств размера K
void printSubsets(vector<int>& A, int K) {
    // Инициализация битовой маски
    int mask = 0;

    // Перебор всех подмножеств
    for (int i = 0; i < (1 << A.size()); i++) {
        // Создание подмножества
        vector<int> subset;
        for (int j = 0; j < A.size(); j++) {
            if (i & (1 << j)) {
                subset.push_back(A[j]);
            }
        }

        // Проверка взаимной простоты всех элементов подмножества
        bool isCoprime = true;
        for (int k = 0; k < subset.size(); k++) {
            for (int l = k + 1; l < subset.size(); l++) {
                if (!isCoprime(subset[k], subset[l])) {
                    isCoprime = false;
                    break;
                }
            }
        }

        // Вывод подмножества, если оно состоит из попарно взаимно простых чисел
        if (isCoprime) {
            cout << "Подмножество: ";
            for (int m = 0; m < subset.size(); m++) {
                cout << subset[m] << " ";
            }
            cout << endl;
        }
    }
}
*/


int main() {
    std::cin >> counterNums >> counterElements;

    int* arr = new int[counterNums];
    for(unsigned index = 0; index < counterNums; index++) {
        std::cin >> arr[index];
    }

    

    return 0;
}

/*
while(mask <= STOP){
    mask ^= chekPos;
    if(mask & chekPos){                 
        mask |= (1 << cnt - 1) - 1;
        cnt = 0;
        chekPos = 1;       
    }                                   
    else {
        // mask |= ...
        ++cnt;
        chekPos <<= 1;
    }
}

*/
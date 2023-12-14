#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// Задание #2

int main() {
    int number;
    cout << "Enter number: "; cin >> number;
    int flag = 0;
    int **matrix = new int*[number];
    for(int i = number - 1; i >= 0; i--) {
        matrix[i] = new int[number];
        for(int j = 0; j < number; j++) {
            matrix[i][j] = flag;
            flag = abs(flag - 1);
        }
    }

    cout << "View matrix" << endl;
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    std::ofstream writeFile;
    writeFile.open("createMatrix.txt");
    if (writeFile.is_open()) {
        for(int i = 0; i < number; i++) {
            for(int j = 0; j < number; j++) {
                writeFile << matrix[i][j] << " ";
            }
            writeFile << endl;
        }
    } else {
        cout << "File opening error" << endl;
    }
    writeFile.close();
    return 0;
}
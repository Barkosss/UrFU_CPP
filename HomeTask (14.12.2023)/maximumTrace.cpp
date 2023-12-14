#include<iostream>
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// Задание #1

int main() {
    int n, maxSum = 0, currSum = 0;
    std::ifstream readFile("maximumTrace.txt");
    if (readFile.is_open()) { // Если получилось открыть файл
        while(!readFile.eof()) {
            readFile >> n;
            int **matrix = new int*[n]{ 0 };

            // Запись матрицы
            for(int i = 0; i < n; i++) {
                matrix[i] = new int[n]{ 0 };
                for(int j = 0; j < n; j++) {
                    readFile >> matrix[i][j];
                }
            }

            // Вывод матрицы
            cout << "View matrix" << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            // Подсчёт суммы диагонали
            for(int i = 0; i < n; i++) currSum += matrix[i][i];

            if (maxSum < currSum) {
                std::ofstream writeFile;
                writeFile.open("maximumTraceInfo.txt");
                if (writeFile.is_open()) { // Если получилось открыть файл
                    for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                            writeFile << matrix[i][j] << " ";
                        }
                        writeFile << endl;
                    }

                } else { // Если не получилось открыть файл
                    cout << "File opening error" << endl;
                    return 0;
                }
                writeFile.close();
                maxSum = currSum; // Перезаписываем максимальную сумму
            }
            currSum = 0; // Обнуляем сумму

            // Удаляем матрицу
            for(int i = 0; i < n; i++) delete matrix[i];
            delete matrix;
        }

    } else { // Если не получилось открыть файл
        cout << "File opening error" << endl;
        return 0;
    }
    
    readFile.close();
    return 0;
}
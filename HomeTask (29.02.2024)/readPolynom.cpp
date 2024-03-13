#include<iostream>
#include<fstream>
#include<string>

#include "readPolynom.h"
#include "writePolynom.h"
#include "Actions.h"
#include "Polynom.h"
#include "sum.h"
#include "sub.h"
#include "multi.h"
#include "divide.h"
#include "getDiffer.h"
#include "getFactorDiffer.h"
#include "checkInteger.h"
#include "getValue.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

// Чтение полиномов из файла
void readPolynom(ifstream&readFile, ofstream&writeFile) {

    // Ошибка открытия файла на чтение
    if (!readFile.is_open()) {
        cout << "Error: Read file isn't open" << endl;
        return;
    }

    // Ошибка открытия файла на запись
    if (!writeFile.is_open()) {
        cout << "Error: Write file isn't open" << endl;
        return;
    }

    int counterPolynoms, counterActions, counterFactor;
    readFile >> counterPolynoms >> counterActions;

    Actions actions;
    string *arrayString = new string[counterActions];
    // Чтение действий
    for(int indexAction = 0; indexAction < counterActions; indexAction++) {
        readFile >> arrayString[indexAction];
    }
    actions.counter = counterActions;
    actions.array = arrayString;

    Polynom* polynoms = new Polynom[counterPolynoms];
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        Polynom arrayPolynom;

        // Количество коэффициентов
        readFile >> counterFactor;
        arrayPolynom.length = counterFactor;

        // Массив из коэффициентов
        int *array = new int[counterFactor];
        for(int indexFactor = 0; indexFactor < counterFactor; indexFactor++) {
            readFile >> array[counterFactor - indexFactor - 1];
        }

        arrayPolynom.array = array;
        polynoms[indexPolynom] = arrayPolynom;
    }

    string action;
    int intResult;
    Polynom polynomResult;

    for(int indexAction = 0; indexAction < counterActions; indexAction++) {
        action = actions.array[indexAction];

        // Какой-то прикол... Пока что так решаю...
        if (action == "") {
            continue;
        }

        if (action == "sum") { // Сумма многочленов
            polynomResult = sum(polynoms, counterPolynoms);

            writePolynom(writeFile, &polynomResult);
        }
        else if (action == "sub") { // Разность многочленов
            polynomResult = sub(polynoms, counterPolynoms);

            writePolynom(writeFile, &polynomResult);
        }
        else if (action == "multi") { // Произведение многочленов
            polynomResult = multi(polynoms, counterPolynoms);

            writePolynom(writeFile, &polynomResult);
        }
        else if (action == "divide") { // Частное от многочленов
            polynomResult = divide(polynoms, counterPolynoms);

            writePolynom(writeFile, &polynomResult);
        }
        else if (action == "getDiffer") { // Получить производную в точке
            string stringValue = actions.array[++indexAction];

            // Проверка, что строка является целым числом
            if (!checkInteger(stringValue)) {
                cout << "Error: The value for finding a function at a point is not an integer" << endl;
                return;
            }

            int intValue = stoi(stringValue);
            getDiffer(writeFile, polynoms, counterPolynoms, intValue);
            break;     
        }
        else if (action == "getFactorDiffer") { // Получить коэффициенты производной
            getFactorDiffer(writeFile, polynoms, counterPolynoms);
            break;
        }
        else if (action == "getValue") { // Получить значение в точке
            string stringValue = actions.array[++indexAction];

            // Проверка, что строка является целым числом
            if (!checkInteger(stringValue)) {
                cout << "Error: The value for finding a function at a point is not an integer" << endl;
                return;
            }

            int intValue = stoi(stringValue);
            getValue(polynoms, counterPolynoms, intValue, writeFile);
            break;
        }
        else { // Если не было найдено действие
            cout << "Action: \"" << action << "\" isn't found" << endl;
        }
    }
}
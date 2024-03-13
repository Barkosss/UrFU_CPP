#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

#include "func.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
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

// Запись полиномов в файл
void writePolynom(std::ofstream&writeFile, Polynom*polynom) {
    
    try {
        string stringPolynom = "";
        int lengthPolynom = polynom->length;
        int* arrayPolynom = polynom->array;

        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            if (!arrayPolynom[indexFactor]) {
                continue;
            }
            // Представление многочленов
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }

        stringPolynom += std::to_string(arrayPolynom[indexFactor]);
        writeFile << stringPolynom << std::endl << std::endl;
    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}

// Сумма полиномов
Polynom sum(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxCounterFactor = 0, counterFactor;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        maxCounterFactor = std::max(polynoms[indexPolynom].length, maxCounterFactor);
    }

    // Массив с коэффициентами
    int *arrayFactor = new int[maxCounterFactor]{ 0 };

    // Складываем многочлены с массивом
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        // Пробегаемся по коэффициентам многочлена
        for(int indexFactor = 0; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor] += polynoms[indexPolynom].array[indexFactor];
        }
    }

    result.length = maxCounterFactor;
    result.array = arrayFactor;

    return result;
}

// Разность полиномов
Polynom sub(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxCounterFactor = 0, counterFactor;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        maxCounterFactor = std::max(polynoms[indexPolynom].length, maxCounterFactor);
    }

    // Массив с коэффициентами
    int *arrayFactor = new int[maxCounterFactor]{ 0 };

    // Заполняем первый многочлен в массив
    int counterFactorOne = polynoms[0].length;
    for(int indexFactor = 0; indexFactor < counterFactorOne; indexFactor++) {
        arrayFactor[indexFactor] = polynoms[0].array[indexFactor];
    }

    // Вычитаем из результативного массива следующие многочлены
    for(int indexPolynom = 1; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        // Пробегаемся по коэффициентам многочлена
        for(int indexFactor = 0; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor] -= polynoms[indexPolynom].array[indexFactor];
        }
    }

    result.length = maxCounterFactor;
    result.array = arrayFactor;

    return result;
}

// Произведение полиномов
Polynom multi(Polynom* polynoms, int counterPolynoms) {
    Polynom result;

    // Находим максимальную степень
    int maxDegreePolynom = -1;
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        
        for(int jndexPolynom = 0; jndexPolynom < counterPolynoms; jndexPolynom++) {
            if (indexPolynom == jndexPolynom) {
                continue;
            }

            maxDegreePolynom = std::max(maxDegreePolynom, polynoms[indexPolynom].length * polynoms[jndexPolynom].length);
        }
    }
    maxDegreePolynom--;

    int *arrayFactor = new int[maxDegreePolynom];

    // Заполняем нулями
    for(int indexFactor = 0; indexFactor < maxDegreePolynom; indexFactor++) {
        arrayFactor[indexFactor] = 0;
    }

    // Произведение первых двух
    for (int indexFactor = 0; indexFactor < polynoms[0].length; indexFactor++) {
		for (int jndexFactor = 0; jndexFactor < polynoms[1].length; jndexFactor++) {
			arrayFactor[indexFactor + jndexFactor] += polynoms[0].array[indexFactor] * polynoms[1].array[jndexFactor];
		}
	}

    // Находим произведение
    int counterFactor;
    for(int indexPolynom = 2; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;

        for (int indexFactor = 0; indexFactor < maxDegreePolynom; indexFactor++) {
            for (int jndexFactor = 0; jndexFactor < polynoms[indexPolynom].length; jndexFactor++) {
                arrayFactor[indexFactor + jndexFactor] += arrayFactor[indexFactor] * polynoms[indexPolynom].array[jndexFactor];
            }
        }
    }

    result.length = maxDegreePolynom;
    result.array = arrayFactor;
    
    return result;
}

// Деление полиномов
Polynom divide(Polynom*polynoms, int counterPolynoms) {
    Polynom result;

    // Получаем количество коэффициентов первого многочлена
    int counterFactor = polynoms[0].length;
    // Создаем массив для хранения коэффициентов результирующего многочлена
    int* arrayFactor = new int[counterFactor + 1];

    // Выбираем первый многочлен в качестве делимого
    Polynom dividend = polynoms[0]; // Делимое

    // Перебираем остальные многочлены в качестве делителей
    for (int indexPolynom = 1; indexPolynom < counterPolynoms; indexPolynom++) {
        Polynom divisor = polynoms[indexPolynom]; // Делитель
        
        // Находим степень частного
        int quotientDegree = dividend.length - divisor.length + 1;
        
        // Коэффициенты частного
        int* quotientFactor = new int[quotientDegree];
        
        // Выполняем деление многочленов
        for (int indexFactor = 0; indexFactor < quotientDegree; indexFactor++) {
            // Вычисляем текущий коэффициент частного
            quotientFactor[indexFactor] = dividend.array[indexFactor] / divisor.array[0];
            
            // Вычисляем остаток от деления
            for (int jndexFactor = 0; jndexFactor < divisor.length; jndexFactor++) {
                dividend.array[indexFactor + jndexFactor] -= quotientFactor[indexFactor] * divisor.array[jndexFactor];
            }
        }
        
        // Освобождаем память изначального делимого
        delete[] dividend.array;
        
        // Обновляем делимое с новым остатком
        dividend.length = dividend.length - divisor.length + 1;
        dividend.array = quotientFactor;
    }

    // Заполняем ответ
    result.length = dividend.length;
    result.array = dividend.array;
    
    return result;
}

// Получить производную полинома в точке
void getDiffer(std::ofstream&writeFile, Polynom*polynoms, int counterPolynoms, int intValue) {
    Polynom *resultPolynoms = new Polynom[counterPolynoms];
    int counterFactor, *arrayFactor;

    // Прохождение по многочленам -> Нахождение производной
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;
        int indexFactor = 1;
        for(; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor - 1] = polynoms[indexPolynom].array[indexFactor] * indexFactor;
        }

        resultPolynoms[indexPolynom].length = indexFactor - 1;
        resultPolynoms[indexPolynom].array = arrayFactor;
    }

    // ------ ЗАПИСЬ В ФАЙЛ ------

    int resultDiffer;
    std::string stringPolynom;
    int lengthPolynom; int *arrayPolynom;
    // Прохождение по многочленам -> Нахождение значения в точке
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        resultDiffer = 0;
        stringPolynom = "";
        lengthPolynom = resultPolynoms[indexPolynom].length;
        arrayPolynom = resultPolynoms[indexPolynom].array;

        // Прохождение по коэффициентам многочлена
        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Результат
            resultDiffer += arrayPolynom[indexFactor] * degree(intValue, indexFactor);
            // Представление многочлена
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }
        
        // Повторяем действия для последнего, свободного, коэффициента
        resultDiffer += arrayPolynom[indexFactor];
        stringPolynom += std::to_string(arrayPolynom[indexFactor]);

        writeFile << "f'(" << intValue << ") = " << stringPolynom << " = " << resultDiffer << std::endl;
    }
}

// Получить коэффициенты производной полинома
void getFactorDiffer(std::ofstream&writeFile, Polynom*polynoms, int counterPolynoms) {
    Polynom *resultPolynoms = new Polynom[counterPolynoms];
    int counterFactor, *arrayFactor;

    // Прохождение по многочленам -> Нахождение производной
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        counterFactor = polynoms[indexPolynom].length;
        int indexFactor = 1;
        for(; indexFactor < counterFactor; indexFactor++) {
            arrayFactor[indexFactor - 1] = polynoms[indexPolynom].array[indexFactor] * indexFactor;
        }

        resultPolynoms[indexPolynom].length = indexFactor - 1;
        resultPolynoms[indexPolynom].array = arrayFactor;
    }

    // ------ ЗАПИСЬ В ФАЙЛ ------

    std::string stringPolynom;
    int lengthPolynom, *arrayPolynom;

    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        stringPolynom = "";
        lengthPolynom = resultPolynoms[indexPolynom].length;
        arrayPolynom = resultPolynoms[indexPolynom].array;

        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Представление многочленов
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }

        stringPolynom += std::to_string(arrayPolynom[indexFactor]);
        writeFile << stringPolynom << std::endl << std::endl;
    }
}

// Получить значение в точке
void getValue(Polynom*polynoms, int counterPolynoms, int intValue, std::ofstream&writeFile) {
    
    int result;
    string stringPolynom;
    int lengthPolynom; int* arrayPolynom;
    // Проход по многочленам
    for(int indexPolynom = 0; indexPolynom < counterPolynoms; indexPolynom++) {
        result = 0;
        stringPolynom = "";
        lengthPolynom = polynoms[indexPolynom].length;
        arrayPolynom = polynoms[indexPolynom].array;

        // Проход по коэффициентам многочлена
        int indexFactor = lengthPolynom - 1;
        for(; indexFactor > 0; indexFactor--) {
            // Результат
            result += arrayPolynom[indexFactor] * degree(intValue, indexFactor);
            // Представление многочлена
            stringPolynom += std::to_string(arrayPolynom[indexFactor]) + "x**" + std::to_string(indexFactor) + " + ";
        }
        
        // Повторяем действия для последнего, свободного, коэффициента
        result += arrayPolynom[indexFactor];
        stringPolynom += std::to_string(arrayPolynom[indexFactor]);

        writeFile << "f(" << intValue << ") = " << stringPolynom << " = " << result << std::endl;
    }

    writeFile << std::endl;
}

// Проверка строки на число
bool checkInteger(string stringValue) {
    int valueLength = stringValue.length();
    for(int index = (stringValue[0] == '-'); index < valueLength; index++) {
        if (!('0' <= stringValue[index] && stringValue[index] <= '9')) {
            return false;
        }
    }
    return true;
}

int degree(int value, int degreeValue) {
    int result = 1;

    for(int index = 0; index < degreeValue; index++) {
        result *= value;
    }

    return result;
}
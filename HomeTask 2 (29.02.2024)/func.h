#pragma once

// Структура полинома
struct Polynom {
    int length;
    int *array;
};

// Структура Действий (Количество | String массив из действий)
struct Actions {
    int counter;
    std::string *array;
};

// Чтение полиномов из файла
void readPolynom(std::ifstream&readFile, std::ofstream&writeFile, Polynom* polynoms);

// Запись м=полиномов в файл
void writePolynom(std::ofstream&, Polynom*);

// Получить значение в точке и записать его в файл
void getValue(Polynom*, int, int, std::ofstream&);

// Получить производную полинома
Polynom getDiffer(Polynom*, int);

// Получить коэффициенты проиводной
Polynom getFactorDiffer(Polynom*, int);

// Сумма полиномов
Polynom sum(Polynom*, int);

// Разность полиномов
Polynom sub(Polynom*, int);

// Произведение полиномов
Polynom multi(Polynom*, int);

// Частно полиномов
Polynom divide(Polynom*, int);

// Проверить, что строка это число
bool checkNumber(std::string);

// Возведение в степень
int degree(int, int);
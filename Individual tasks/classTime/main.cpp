#include<fstream>
#include<iostream>

#include "Time.h"

/*
Разработать класс Time (время) с членами: часы, минуты, секунды.
Переопределить оператор + для добавления к заданному моменту
времени некоторого отрезка времени. А также переопределить
операторы >, <. Написать тестирующую программу.
*/


int main() {
    std::ifstream readFile("data.txt");
    
    unsigned short hour, minute, seconds, day, month;
    unsigned int year;
    int counterExpression, counterArguments;
    readFile >> counterExpression;

    Date *times = new Date[counterExpression];
    for(int indexExpression = 0; indexExpression < counterExpression; indexExpression++) {
        readFile >> counterArguments;

        // Если один аргумент - Запись время в память
        if (counterArguments == 1) {
            readFile >> hour >> minute >> seconds >> day >> month >> year;
            times[indexExpression].setTime(hour, minute, seconds, day, month, year);
        }

        // Если три аргумента - Вычислить: Сложить или сравнить время
        else if (counterArguments == 3) {
            // ...
        }

        // Ошибка
        else {
            std::cout << "Error: ..." << std::endl;
            return 404;
        }
    }

    return 0;
}
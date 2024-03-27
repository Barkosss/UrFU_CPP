#include <iostream>

#include "Time.h"

// Создать дату
void Date::setTime(unsigned short hour, unsigned short minute, unsigned short seconds, unsigned short day, unsigned short month, unsigned int year) {
    
    // Проверка часов
    if (0 <= hour && hour <= 23) {
        hour = hour;
    } else {
        std::cout << "Error: ..." << std:: endl;
    }

    // Проверка минут
    if (0 <= minute && minute <= 59) {
        minute = minute;
    } else {
        std::cout << "Error: ..." << std:: endl;
    }

    // Проверка секунд
    if (0 <= seconds && seconds <= 59) {
        seconds = seconds;
    } else {
        std::cout << "Error: ..." << std:: endl;
    }

    // Проверка дня
    if (1 <= day && day <= 31) {
        day = day;
    } else {
        std::cout << "Error: ..." << std:: endl;
    }


    // Проверка месяца
    if (1 <= month && month <= 12) {
        month = month;
    } else {
        std::cout << "Error: ..." << std:: endl;
    }

    year = year;
}

// Сложение даты
Date Date::operator+(const Date&right) {
    
}

// Разность даты
Date Date::operator-(const Date&right) {


}

// Сравнить две даты -> Больше
bool Date::operator>(const Date&right) {

    return true;
}

// Сравнить две даты -> Меньше
bool Date::operator<(const Date&right) {


    return true;
}

// Сравнить две даты -> Равны
bool Date::operator==(const Date&right) {

    return true;
}
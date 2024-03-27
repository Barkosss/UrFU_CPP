#pragma once

class Date {
private:
    unsigned short hour;
    unsigned short minute;
    unsigned short seconds;
    unsigned short day;
    unsigned short month;
    unsigned int year;
    
public:
    Date getTime() {};
    void setTime(unsigned short hour, unsigned short minute, unsigned short seconds, unsigned short day, unsigned short month, unsigned int year) {};

    // Сложение даты
    Date operator+(const Date&right) {};

    // Разность даты
    Date operator-(const Date&right) {};

    // Сравнить две даты -> Больше
    bool operator>(const Date&right) {};

    // Сравнить две даты -> Меньше
    bool operator<(const Date&right) {};

    // Сравнить две даты -> Равны
    bool operator==(const Date&right) {};
};
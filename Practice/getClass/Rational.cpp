#include<iostream>
#include<fstream>

#include "Rational.h"

class Rational {
    public:

    // Сложение дробей
    Rational operator +(const Rational &right) {
        
        // Если знаменатели разные
        if (denominator != right.denominator) {
            numerator = (numerator * right.denominator) + (denominator * right.numerator);
            denominator = right.denominator * denominator;
        } 
        // Если знаменатели одинаковые
        else {
            numerator += right.numerator;
        }

        return {numerator, denominator};
    }

    // Разность дробей
    Rational operator -(const Rational &right) {

        // Если знаменатели разные
        if (denominator != right.denominator) {
            numerator = (numerator * right.denominator) - (denominator * right.numerator);
            denominator = right.denominator * denominator;
        } 
        // Если знаменатели одинаковые
        else {
            numerator -= right.numerator;
        }

        return {numerator, denominator};
    }

    // Умножение дробей
    Rational operator *(const Rational &right) {

        numerator *= right.numerator;
        denominator *= right.denominator;

        return {numerator, denominator};
    }

    // Деление дробей
    Rational operator /(const Rational &right) {

        numerator *= right.denominator;
        denominator *= right.numerator;

        return {numerator, denominator};
    }

    // Сравнение: Больше
    bool operator >(const Rational &right) {
        // ...
    }

    // Сравнение: Меньше
    bool operator <(const Rational &right) {
        // ...
    }

    // Сравнение: Больше или равно
    bool operator >=(const Rational &right) {
        // ...
    }

    // Сравнение: Меньше или равно
    bool operator <=(const Rational &right) {
        // ...
    }

    // Сравнение: Не равно
    bool operator !=(const Rational &right) {

        if (numerator == right.numerator && denominator == right.numerator) {
            return false;
        }
        
        return true;
    }

    // Присваение числителя
    void updateNumerator(int numer) {
        numerator = numer;
    }

    // Присваение знаметеля
    void updateDenominator(unsigned denom) {
        denominator = denom;
    }

    ~Rational() {}

    // Конструктор
    Rational(int num, unsigned denom) {
        numerator = num;
        denominator = (denom) ? (denom) : (1);

        reduce(numerator, denominator);
    }

    // Конструктор по умолчанию
    Rational(): numerator(0), denominator(1) {}

    private:
    int numerator;
    unsigned denominator;

    // Сокращение дроби
    Rational reduce(int numer, unsigned denom) {
        // ...
    }
};
#pragma once

class Rational {
    public:

    // Сложение дробей
    Rational operator +(const Rational &right) {}

    // Разность дробей
    Rational operator -(const Rational &right) {}

    // Умножение дробей
    Rational operator *(const Rational &right) {}

    // Деление дробей
    Rational operator /(const Rational &right) {}

    // Присваивание
    Rational operator =(const Rational &right) {}

    // Сравнение: Больше
    bool operator >(const Rational &right) {}

    // Сравнение: Меньше
    bool operator <(const Rational &right) {}

    // Сравнение: Больше или равно
    bool operator >=(const Rational &right) {}

    // Сравнение: Меньше или равно
    bool operator <=(const Rational &right) {}

    // Сравнение: Не равно
    bool operator !=(const Rational &right) {}

    // Присваение числителя
    void updateNumerator(int numer) {}

    // Присваение знаметеля
    void updateDenominator(int denom) {}

    ~Rational() {}

    // Конструктор
    Rational(int, int) {}

    // Конструктор по умолчанию
    Rational() {}

    private:
    int numerator;
    unsigned denominator;

    // Сокращение дроби
    void reduce(int, unsigned) {}
};
#include<iostream>
#include<string>

#include "checkInteger.h"

using std::string;

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
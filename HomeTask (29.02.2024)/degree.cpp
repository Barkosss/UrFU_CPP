#include <iostream>

#include "degree.h"

int degree(int value, int degreeValue) {
    int result = 1;

    for(int index = 0; index < degreeValue; index++) {
        result *= value;
    }

    return result;
}
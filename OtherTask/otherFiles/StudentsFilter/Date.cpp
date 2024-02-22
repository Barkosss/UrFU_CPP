#include "Date.h"

bool Date::operator > (Date&rightDate) {

    // Первая дата (Первый аргумент)
    unsigned short oneDay = this->day;
    unsigned short oneMonth = this->month;
    unsigned int oneYear = this->year;

    // Вторая дата (Второй аргумент)
    unsigned short twoDay= rightDate.day;
    unsigned short twoMonth = rightDate.month;
    unsigned int twoYear = rightDate.year;

    if (oneYear > twoYear) {
        return true;
    } else {
        if (oneMonth > twoMonth) {
            return true;
        } else {
            if (oneDay > twoDay) {
                return true;
            } else {
                return false;
            }
        }
    }
}
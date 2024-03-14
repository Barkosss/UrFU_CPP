#include<string>

using std::string;
using std::to_string;

// Конвертировать временную метку в дату
string ConvertTimestamp(long long timestamp) {
    string resultTime = "";

    short daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int currentYear = 1970, daysTillNow = 0, extraTime = 0, extraDays = 0;
    long int day = 0, month = 0, hours = 0, minutes = 0, seconds = 0, leapYear = 0;

    // Сколько дней с 1970 до текущего момента прошло
    daysTillNow = timestamp / (24 * 60 * 60);
    extraTime = timestamp % (24 * 60 * 60);


    // Вычисляем год
    while(true) {

        // Вычитаем год -> Високосный год
        if (currentYear % 400 == 0 || (currentYear % 4 == 0 && currentYear % 100 != 0)) {
            if (daysTillNow < 366) {
                break;
            }
            daysTillNow -= 366;
        }
        // Вычитаем год -> Не високосный код
        else {
            if (daysTillNow < 365) {
                break;
            }
            daysTillNow -= 365;
        }

        currentYear++;
    }

    // Обновляем дополнительное время, так как иначе мы получим предыдущий день
    extraDays = daysTillNow + 1;

    // Если текущий год високосный -> Обновляем флаг
    if (currentYear % 400 == 0 || (currentYear % 4 == 0 && currentYear % 100 != 0)) {
        leapYear = 1;
    }

    long int indexMonth = 0;
    // Если текущий год - Високосный
    if (leapYear) {
        while(true) {
            // Месяц - Февраль
            if (indexMonth == 1) {

                if (extraDays - 29 < 0) {
                    break;
                }
                month++;
                extraDays -= 29;
            }
            // Другие месяца
            else {

                if (extraDays - daysOfMonth[indexMonth] < 0) {
                    break;
                }

                month++;
                extraDays -= daysOfMonth[indexMonth];
            }

            indexMonth++;
        }
    }
    // Если текущий код - Не високосный
    else {

        while(true) {
            if (extraDays - daysOfMonth[indexMonth] < 0) {
                break;
            }

            month++;
            extraDays -= daysOfMonth[indexMonth];
            indexMonth++;
        }
    }

    if (extraDays > 0) {
        month++;
        day = extraDays;
    } else {
        if (month == 2 && leapYear) {
            day = 29;
        } else {
            day = daysOfMonth[month - 1];
        }
    }

	hours = extraTime / 3600;
	minutes = (extraTime % 3600) / 60;
	seconds = (extraTime % 3600) % 60;
    
    resultTime = ((to_string(day).length() == 1) ? ("0") : ("")) +to_string(day) + "/" + ((to_string(month).length() == 1) ? ("0") : ("")) + to_string(month) + "/" + to_string(currentYear) + " " + ((to_string(hours).length() == 1) ? ("0") : ("")) +to_string(hours) + ":" + ((to_string(minutes).length() == 1) ? ("0") : ("")) + to_string(minutes) + "." + ((to_string(seconds).length() == 1) ? ("0") : ("")) + to_string(seconds);


    // Возращаем результат
    return resultTime;
}
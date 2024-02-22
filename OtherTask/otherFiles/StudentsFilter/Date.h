#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned int year;

    bool operator > (Date&rightDate);
};

#endif
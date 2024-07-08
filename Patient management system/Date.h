#ifndef DATE_H
#define DATE_H

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
} Date;


Date* createDate(int year, int month, int day, int hour, int min);

#endif // DATE_H

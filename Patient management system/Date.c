#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

static int isValidDate(int year, int month, int day, int hour, int min) {
    if (year <= 1900 || year >= 2024) {
        printf("Year must be between 1900 and 2024!\n");
        return 0;
    }
    if (month <= 1 || month >= 12) {
        printf("Month must be between 1 and 121\n");
        return 0;
    }
    if (day <= 1 || day >= 31) {
        printf("Day must be between 1 and 31\n");
        return 0;
    }
    if (hour <= 0 || hour >= 23) {
        printf("Hour must be between 0 and 23\n");
        return 0;
    }
    if (min <= 0 || min >= 59) {
        printf("Min must be between 0 and 59\n");
        return 0;
    }
    return 1;
}

Date* createDate(int year, int month, int day, int hour, int min) {
    if (!isValidDate(year, month, day, hour, min)) {
        printf("Invalid date values: %d-%d-%d %d:%d\n", year, month, day, hour, min);
        return NULL;
    }

    Date* newDate = (Date*)malloc(sizeof(Date));
    if (!newDate) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    newDate->year = year;
    newDate->month = month;
    newDate->day = day;
    newDate->hour = hour;
    newDate->min = min;

    return newDate;
}

#ifndef VISIT_H
#define VISIT_H

#include "Date.h"
#include "Doc.h"

typedef struct {
    Date tArrival;
    Date tDismissed;
    float duration;
    Doc* doctor;
    char* vSummary;
} Visit;

Visit* createVisit(Date tArrival, Date tDismissed, float duration, Doc* doctor, const char* vSummary);

#endif // VISIT_H

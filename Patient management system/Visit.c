#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Visit.h"

Visit* createVisit(Date tArrival, Date tDismissed, float duration, Doc* doctor, const char* vSummary) {
    if (duration < 0) {
        printf("Invalid visit duration: %f\n", duration);
        return NULL;
    }

    Visit* newVisit = (Visit*)malloc(sizeof(Visit));
    if (!newVisit) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newVisit->tArrival = tArrival;
    newVisit->tDismissed = tDismissed;
    newVisit->duration = duration;
    newVisit->doctor = doctor;
    if (vSummary) {
        newVisit->vSummary = _strdup(vSummary);
        if (!newVisit->vSummary) {
            printf("Memory allocation for vSummary failed\n");
            free(newVisit);
            return NULL;
        }
    }
    else {
        newVisit->vSummary = NULL;
    }

    return newVisit;
}

#ifndef PATIENT_H
#define PATIENT_H

#include "Visit.h"
#include "VisitStack.h"

#define ID_MAX_LENGTH 11

typedef struct {
    char* name;
    char ID[ID_MAX_LENGTH];
    unsigned char allergies;
    Stack* visits;
    int nVisits;
} Patient;

Patient* createPatient(const char* name, const char* ID, unsigned char allergies, Stack* visits, int nVisits);

#endif // PATIENT_H

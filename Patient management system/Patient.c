#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Patient.h"
#include "Doc.h"
#include "VisitStack.h"

static int validateID(const char* ID) {
    for (int i = 0; i < ID_MAX_LENGTH - 1; ++i) {
        if (!isdigit(ID[i])) {
            return 0;  // Non-numeric character found
        }
    }
    return 1;
}


static int isValidPatient(const char* name, const char* ID, unsigned char allergies, int nVisits) {
    if (!validateName(name)) {
        printf("Name should contain alphabetic characters and spaces only!\n");
        return 0;
    }
    if (!validateID(ID)) {
        printf("ID should contain only digits!\n");
        return 0;
    }
    if (strlen(ID) != ID_MAX_LENGTH - 1) {
        printf("Length of ID must be 9!\n");
        return 0; // Assuming ID length of 10 + '\0'
    }
        if (nVisits < 0) return 0;
    return 1;
}


Patient* createPatient(const char* name, const char* ID, unsigned char allergies, Stack* visits, int nVisits) {
    if (!isValidPatient(name, ID, allergies, nVisits)) {
        fprintf(stderr, "Invalid patient values: name=%s, ID=%s, allergies=%u, nVisits=%d\n", name, ID, allergies, nVisits);
        return NULL;
    }

    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (!newPatient) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newPatient->name = (char*)malloc(strlen(name) + 1);  // Allocate memory for the string (+1 for null terminator)
    if (!newPatient->name) {
        printf("Memory allocation for name failed\n");
        free(newPatient);
        return NULL;
    }
    strcpy(newPatient->name, name);
    strncpy(newPatient->ID, ID, ID_MAX_LENGTH);
    newPatient->ID[ID_MAX_LENGTH - 1] = '\0'; // Ensure null-termination
    newPatient->allergies = allergies;
    newPatient->visits = createStack();
    newPatient->nVisits = nVisits;
    return newPatient;
}

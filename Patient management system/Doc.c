#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Doc.h"

int isCharOrSpace(char c) {
    return (isalpha(c) || c == ' ');
}

int validateName(const char* name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isCharOrSpace(name[i])) {
            return 0;  // Invalid character found
        }
    }
    return 1;  // Name is valid
}

static int validateLicense(const char* license) {
    for (int i = 0; i < LICENSE_MAX_LENGTH - 1; ++i) {
        if (!isdigit(license[i])) {
            return 0;  // Non-numeric character found
        }
    }
}


static int isValidDoc(const char* name, const char* nLicense, int nPatients) {
    if (!validateName(name)) {
        printf("Name should contain alphabetic characters and spaces only!\n");
        return 0;
    }
    if (strlen(nLicense) != LICENSE_MAX_LENGTH - 1) {
        printf("License must be a number of 7 digits!\n");
        return 0;
    }
    if (!validateLicense(nLicense)) {
        printf(" License should contain only digits!\n");
        return 0;
    }

    if (nPatients <= 0 || nPatients >= 4) return 0;
    return 1;
}

Doc* createDoc(const char* name, const char* nLicense, int nPatients) {
    // Validate input parameters
    if (!isValidDoc(name, nLicense, nPatients)) {
        printf("Invalid Doctor data\n");
        return NULL;
    }
    
    Doc* newDoc = (Doc*)malloc(sizeof(Doc));
    if (!newDoc) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newDoc->name = (char*)malloc(strlen(name) + 1);  // Allocate memory for the string (+1 for null terminator)
    if (!newDoc->name) {
        printf("Memory allocation for name failed\n");
        free(newDoc);
        return NULL;
    }
    strcpy(newDoc->name, name);

    strncpy(newDoc->nLicense, nLicense, LICENSE_MAX_LENGTH);
    newDoc->nLicense[LICENSE_MAX_LENGTH - 1] = '\0';  // Ensure null-termination
    newDoc->nPatients = nPatients;

    return newDoc;
}
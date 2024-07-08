#include <stdio.h>
#include <stdlib.h>
#include "PInLine.h"

PInLine* createListNode(Patient lpatient) {
    PInLine* newNode = (PInLine*)malloc(sizeof(PInLine));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    newNode->lpatient = lpatient;
    newNode->next = NULL;

    return newNode;
}

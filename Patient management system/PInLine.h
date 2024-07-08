#ifndef PINLINE_H
#define PINLINE_H

#include "Patient.h"

typedef struct PInLine {
    Patient lpatient;
    struct PInLine* next;
} PInLine;


PInLine* createListNode(Patient lpatient);

#endif 

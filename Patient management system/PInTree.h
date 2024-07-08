#ifndef PINTREE_H
#define PINTREE_H

#include "Patient.h"

typedef struct PInTree {
    Patient tpatient;
    struct PInTree* left;
    struct PInTree* right;
} PInTree;

PInTree* createTreeNode(Patient tpatient);

#endif

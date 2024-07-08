#include <stdio.h>
#include <stdlib.h>
#include "PInTree.h"

PInTree* createTreeNode(Patient tpatient) {
    PInTree* newNode = (PInTree*)malloc(sizeof(PInTree));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    newNode->tpatient = tpatient;
    newNode->left = newNode->right = NULL;

    return newNode;
}

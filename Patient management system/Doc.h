#ifndef DOC_H
#define DOC_H

#define LICENSE_MAX_LENGTH 8

typedef struct {
    char* name;
    char nLicense[LICENSE_MAX_LENGTH];
    int nPatients;
} Doc;

Doc* createDoc(const char* name, const char* nLicense, int nPatients);
int validateName(const char* name);

#endif // DOC_H

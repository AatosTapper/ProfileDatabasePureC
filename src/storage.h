
#ifndef STORAGE
#define STORAGE

#include "profile.h"
#include "string.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct 
{
    struct Profile* arr;
    unsigned size; // how many items fit to storage
    unsigned realSize; // how many items are in storage
} 
dynArray;

void initStorage();
void saveToStorage(struct Profile* p);
// caller has to check for NULL
struct Profile* fetchFromStorage(char* name);
void printAllProfiles();
void freeStorage();

#endif
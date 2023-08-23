
#ifndef STORAGE_H
#define STORAGE_H

#include "profile.h"
#include "string.h"
#include "fileSave.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef struct 
{
    struct Profile* arr;
    unsigned size; // how many items fit to storage
    unsigned realSize; // how many items are in storage
} 
dynArray;

// -1 = profile not found
int selectProfile(char* name, char* id);
struct Profile* getSelectedProfile();
void initStorage();
void saveToStorage(struct Profile* p);
void printSelectedProfile();
void printAllProfiles();
void freeStorage();

#endif
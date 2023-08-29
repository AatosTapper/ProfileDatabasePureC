#ifndef FILESAVE_H
#define FILESAVE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "profile.h"

void saveToFile(struct Profile* arr, unsigned realSize);
// Caller must free the memory
struct Profile* readFromFile(unsigned* size);

#endif
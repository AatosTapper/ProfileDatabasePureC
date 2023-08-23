#ifndef FILESAVE_H
#define FILESAVE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "profile.h"

void saveToFile(struct Profile* arr, unsigned realSize);
// arguments are directly changed via pointers
void readFromFile(struct Profile* arr, unsigned* realSize);

#endif
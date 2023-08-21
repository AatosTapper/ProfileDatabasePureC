#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>

void printString(char* ptr);

// caller must delete the memory
char* getString();

#endif


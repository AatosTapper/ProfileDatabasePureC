
#include "storage.h"

dynArray* profiles;

void initStorage()
{
    profiles = malloc(sizeof(dynArray));
    profiles->size = 4;
    profiles->realSize = 0;
    profiles->arr = malloc(sizeof(struct Profile) * profiles->size);
}

void saveToStorage(struct Profile* p)
{
    // resize the array if needed
    if (profiles->size <= profiles->realSize)
    {
        dynArray* newArr = malloc(sizeof(dynArray));
        newArr->size = profiles->size * 2;
        newArr->realSize = profiles->realSize;
        newArr->arr = malloc(sizeof(struct Profile) * newArr->size);
        memcpy(newArr->arr, profiles->arr, sizeof(struct Profile) * profiles->realSize);

        free(profiles->arr);
        free(profiles);
        profiles = newArr;
    }

    profiles->arr[profiles->realSize] = *p;
    profiles->realSize += 1;
}

struct Profile* fetchFromStorage(char* name)
{
    for (unsigned i = 0; i < profiles->realSize; i++)
    {
        if (strcmp(name, profiles->arr[i].name) == 0)
        {
            return &profiles->arr[i];
        }
    }
    printString("Profile wasn't in the database\n");
    
    return NULL;
}

void freeStorage()
{
    free(profiles->arr);
    free(profiles);
}

void printAllProfiles()
{
    printString("\n-----------\n");
    for (unsigned i = 0; i < profiles->realSize; i++)
    {
        printf("Profile %d ", i);

        printString("\n    First Name: ");
        printString(profiles->arr[i].name);

        printString("\n    Last Name: ");
        printString(profiles->arr[i].lastName);

        printString("\n    ID: ");
        printString(profiles->arr[i].id);
        
        printString("\n-----------\n");
    }
}
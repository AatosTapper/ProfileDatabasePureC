
#include "storage.h"

dynArray* profiles;
struct Profile* selectedProfile;

int getProfileByName(char* name)
{
    for (unsigned i = 0; i < profiles->realSize; i++)
    {
        if (strcmp(name, profiles->arr[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void getProfilesFromFile()
{
    unsigned size = 0; // WHY IS THIS 0 ???
    struct Profile* temp = readFromFile(&size);
    
    if (temp == NULL)
    {
        printf("No presaved profiles in the database\n");
        return;
    }
    printf("%d", size);
    for (unsigned i = 0; i < size; i++)
    {
        printf("%s", temp->name);
        saveToStorage(temp);
        temp++;
    }
}

void initStorage()
{
    profiles = malloc(sizeof(dynArray));
    profiles->size = 4;
    profiles->realSize = 0;
    profiles->arr = malloc(sizeof(struct Profile) * profiles->size);
    getProfilesFromFile();
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

int selectProfile(char* name, char* id)
{
    int index = getProfileByName(name);

    if (index == -1)
    {
        return -1;
    }

    if (strcmp(profiles->arr[index].id, id) == 0)
    {
        selectedProfile = &profiles->arr[index];
    }

    else
    {
        return -1;
    }

    return 0;
}

struct Profile* getSelectedProfile()
{
    assert(selectedProfile);
    return selectedProfile;
}

void freeStorage()
{
    saveToFile(profiles->arr, profiles->realSize);
    for (unsigned i = 0; i < profiles->realSize; i++)
    {
        if (profiles->arr == NULL)
        {
            continue;
        }
        free(profiles->arr);
        profiles->arr++;
    }
    free(profiles);
}


// --- printing ---

void printProfile(struct Profile* p)
{
    assert(p);

    printString("\nProfile:");

    printString("\n    ID: ");
    printString(p->id);

    printString("\n    First Name: ");
    printString(p->name);

    printString("\n    Last Name: ");
    printString(p->lastName);    

    printString("\n    Birthday: ");
    printString(p->birthday);

    printString("\n    Personality: ");
    printString(p->personality);

    printString("\n    Description: ");
    printString(p->description);

    printString("\n    Speciality: ");
    printString(p->speciality);

    printString("\n    ----\n");
}

void printSelectedProfile()
{
    if (selectedProfile == NULL)
    {
        printString("You have to select a profile first\n");
        return;
    }

    printProfile(selectedProfile);
}

void printAllProfiles()
{
    for (unsigned i = 0; i < profiles->realSize; i++)
    {
        printProfile(&profiles->arr[i]);
    }
}
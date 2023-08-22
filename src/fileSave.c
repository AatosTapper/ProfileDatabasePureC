
#include "fileSave.h"

char* parseProfile(struct Profile* p)
{
    size_t size = 0;
    unsigned nullSpace = 3; // nullterminator + newline
    size_t fnSize = strlen(p->name) + nullSpace; 
    size += fnSize;
    size_t lnSize = strlen(p->lastName) + nullSpace;
    size += lnSize;
    size_t idSize = strlen(p->id) + nullSpace;
    size += idSize;

    char* output = malloc(size);
    
    
}

void saveToFile(struct Profile* arr, unsigned size, unsigned realSize)
{
    FILE* file = fopen("savedata/save.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "BRUH!\n");
    fclose(file);
}

void readFromFile(struct Profile* arr, unsigned* size, unsigned* realSize)
{

}
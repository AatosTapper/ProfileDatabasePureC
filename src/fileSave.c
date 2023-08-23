
#include "fileSave.h"

void setAndIncrement(char** to, char* from, size_t size)
{
    if (*to && from) {
        memcpy(*to, from, size);
        *to += size;
        if (*to) {
            **to = '\n';
            (*to)++;
        }
    }
}

char* parseProfile(struct Profile* p)
{
    assert(p);
    size_t size = 0;

    size_t fnSize = strlen(p->name);
    size_t lnSize = strlen(p->lastName);
    size_t idSize = strlen(p->id);
    size_t bdSize = strlen(p->birthday);
    size_t personalitySize = strlen(p->personality);
    size_t specialitySize = strlen(p->speciality);
    size_t descriptionSize = strlen(p->description);

    size = fnSize + lnSize + idSize + bdSize +
           personalitySize + specialitySize + descriptionSize + 7; // Include space for newlines and null-terminator

    char* output = malloc(size);
    char* outputPtr = output;

    setAndIncrement(&outputPtr, p->name, fnSize);
    setAndIncrement(&outputPtr, p->lastName, lnSize);
    setAndIncrement(&outputPtr, p->id, idSize);
    setAndIncrement(&outputPtr, p->birthday, bdSize);
    setAndIncrement(&outputPtr, p->personality, personalitySize);
    setAndIncrement(&outputPtr, p->speciality, specialitySize);
    setAndIncrement(&outputPtr, p->description, descriptionSize);

    *outputPtr = '\0';
    return output;
}

char* getFileBuffer(struct Profile* arr, unsigned realSize)
{
    char* buffer = NULL;
    char* bufferStart = NULL;
    
    size_t totalSize = 0;
    for (unsigned i = 0; i < realSize; i++) 
    {
        char* temp = parseProfile(arr);
        totalSize += strlen(temp) + 1;
        free(temp);
        arr++;
    }
    
    buffer = malloc(totalSize);    
    bufferStart = buffer;
    
    arr -= realSize; // Reset arr to the beginning
    for (unsigned i = 0; i < realSize; i++) 
    {
        char* temp = parseProfile(arr);
        size_t tempLength = strlen(temp);
        strcpy(buffer, temp);
        free(temp);
        buffer += tempLength;
        arr++;
    }
    
    return bufferStart;
}

void saveToFile(struct Profile* arr, unsigned realSize)
{
    FILE* file = fopen("savedata/save.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char* buffer = getFileBuffer(arr, realSize);
    
    if (buffer == NULL)
    {
        fclose(file);
        printf("Error writing file\n");
    }

    fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);
    free(buffer);
}

void readFromFile(struct Profile* arr, unsigned* realSize)
{

}
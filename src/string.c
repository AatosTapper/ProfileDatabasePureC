
#include "string.h"

#define MAX_STR_LEN 128

void printString(char* ptr)
{
    if (ptr == NULL)
    {
        printf("Can't print a null string\n");
        return;
    }
    unsigned it = 0;
    while (*ptr != '\0')
    {
        printf("%c", (char)*(ptr++)); 
        it++;
        if (it >= MAX_STR_LEN)
        {
            printf("Max str lenght passed\n");
            break;
        }    
    }
}

char* getString()
{
    char* ptr = NULL;
    ptr = (char*)malloc(sizeof(char) * MAX_STR_LEN);
    scanf("%s", ptr);

    if (ptr == NULL) 
    {
        return (char*)"Error when getting the string\n";
    }

    return ptr;
}
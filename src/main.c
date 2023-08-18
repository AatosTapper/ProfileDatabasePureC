#include <stdlib.h>
#include <stdint.h>
#include "string.h"
#include "storage.h"
#include "profile.h"

int main()
{
    initStorage();

    for (int i = 0; i < 10; i++)
    {
        srand(i);
        struct Profile p;
        p.name = "";
        p.id = "";
        p.lastName = "";

        saveToStorage(&p);
    }

    printAllProfiles();

    return 0;
}
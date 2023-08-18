
#include "loop.h"

void runLoop()
{
    initStorage();
    int stop = 0;
    do 
    {
        executeAction(getAction());

    } while (stop != -1);
    freeStorage();
}

int getAction()
{
    return 0;
}

void executeAction(int a) 
{
    // the idea is that the user selects a profile and can
    // do some stuff to it

    // these aren't in order because the program flow
    // happens via the action return values

    switch (a)
    {
    case 0:
        executeAction(act_selectProfile());
        break;

    case 1:
        executeAction(act_addProfile());
        break;
    
    case 2:
        executeAction(act_deleteProfile());
        break;
    
    case 3:
        executeAction(act_editProfile());
        break;

    case 4:
        executeAction(act_findProfile());
        break;

    default:
        break;
    }
}
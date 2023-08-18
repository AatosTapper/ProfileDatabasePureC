
// "Action" is an operation that the program can execute

// An action can lead to other actions if it
// returns a number corresponding to another action.

// If an action returns -1 it doesn't lead to other actions.

// This behaviour allows for complex looping and branching
// logic, that can be easily implemented:
// -> just return the next action's index

#ifndef ACTION
#define ACTION

#include <stdlib.h>

int act_selectProfile();
int act_addProfile();
int act_deleteProfile();
int act_editProfile();
int act_findProfile();

#endif
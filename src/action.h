
// "Action" is an ui element

// An action can lead to other actions if it
// returns a number corresponding to another action.

// If an action returns -1 it doesn't lead to other actions.

// This behaviour allows for complex looping and branching
// logic, that can be easily implemented:
// -> just return the next action's index

#ifndef ACTION
#define ACTION

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "storage.h"

typedef enum ACTION
{
    EXIT = -2,
    BACK = -1,
    SELECT_PROFILE = 0,
    ADD_PROFILE = 1,
    DELETE_PROFILE = 2,
    EDIT_PROFILE = 3,
    SHOW_ALL_PROFILES = 4,
    HELP = 5,
    SHOW_SELECTED_PROFILE = 6,
    PROFILE_MENU = 7,
    ALL_PROFILES_ACTIONS = 8,
};

int act_mainMenu();
int act_selectProfile();
int act_addProfile();
int act_deleteProfile();
int act_editProfile();
int act_showAllProfiles();
int act_showSelectedProfile();
int act_help();
int act_profileMenu();
int act_allProfilesActions();

#endif
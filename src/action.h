
// "Action" is an ui element

// An action can lead to other actions if it
// returns a number corresponding to another action.

// If an action returns -1 it doesn't lead to other actions.

// This behaviour allows for complex looping and branching
// logic, that can be easily implemented:
// -> just return the next action's index

#ifndef ACTION_H
#define ACTION_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "storage.h"

typedef enum ACTION
{
    EXIT = -2,
    BACK = -1, // Basically MAIN_MENU

    SELECT_PROFILE = 0,
    ADD_PROFILE = 1,
    DELETE_PROFILE = 2,
    EDIT_PROFILE = 3,
    SHOW_ALL_PROFILES = 4,
    HELP = 5,
    SHOW_SELECTED_PROFILE = 6,
    PROFILE_MENU = 7,
    ALL_PROFILES_MENU = 8,
    CHANGE_PROFILE_NAME = 9,
    CHANGE_PROFILE_LAST_NAME = 10,
    CHANGE_PROFILE_ID = 11
} ACTION;

extern ACTION lastAction;

int act_mainMenu();
int act_selectProfile();
int act_addProfile();
int act_deleteProfile();
int act_editProfile();
int act_showAllProfiles();
int act_showSelectedProfile();
int act_help();
int act_profileMenu();
int act_allProfilesMenu();
int act_changeProfileName();
int act_changeProfileLastName();
int act_changeProfileId();

#endif
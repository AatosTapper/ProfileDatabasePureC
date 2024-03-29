
#include "loop.h"

void runLoop()
{
    initStorage();
    int menuVal = 0;
    printString("\n----PROFILE-DATABASE---\n");
    do 
    {
        menuVal = act_mainMenu();
        executeAction(menuVal);

    } while (menuVal != -2);
    freeStorage();
    printString("\n----database-closed---\n");
}

void executeAction(int a) 
{
    if (a <= BACK)
    {
        return;
    }

    switch (a)
    {
    case SELECT_PROFILE:
        executeAction(act_selectProfile());
        break;

    case ADD_PROFILE:
        executeAction(act_addProfile());
        break;
    
    case DELETE_PROFILE:
        executeAction(act_deleteProfile());
        break;
    
    case EDIT_PROFILE:
        executeAction(act_editProfile());
        break;

    case SHOW_ALL_PROFILES:
        executeAction(act_showAllProfiles());
        break;

    case HELP:
        executeAction(act_help());
        break;

    case SHOW_SELECTED_PROFILE:
        executeAction(act_showSelectedProfile());
        break;

    case PROFILE_MENU:
        executeAction(act_profileMenu());
        break;

    case ALL_PROFILES_MENU:
        executeAction(act_allProfilesMenu());
        break;

    case CHANGE_PROFILE_NAME:
        executeAction(act_changeProfileName());
        break;

    case CHANGE_PROFILE_LAST_NAME:
        executeAction(act_changeProfileLastName());
        break;

    case CHANGE_PROFILE_ID:
        executeAction(act_changeProfileId());
        break;

    case CHANGE_PROFILE_BIRTHDAY:
        executeAction(act_changeProfileBirthday());
        break;

    case CHANGE_PROFILE_PERSONALITY:
        executeAction(act_changeProfilePersonality());
        break;

    case CHANGE_PROFILE_SPECIALITY:
        executeAction(act_changeProfileSpeciality());
        break;

    case CHANGE_PROFILE_DESCRIPTION:
        executeAction(act_changeProfileDescription());
        break;

    default:
        break;
    }
}
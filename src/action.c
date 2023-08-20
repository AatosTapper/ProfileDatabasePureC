
#include "action.h"

char getKey()
{
    printString("\nInput: ");
    char* input = getString();
    char key = input[0];
    free(input);
    return key;
}

int act_mainMenu()
{
    printString("\nMain Menu Ⓜ️\n");
    printString(" -- Add profile: a\n");
    printString(" -- Search profile: s\n");
    printString(" -- Show all profiles: p\n");
    printString(" -- Help: h\n");
    printString(" -- Exit: e\n");

    char key = getKey();

    switch (key)
    {
    case 's':
        return SELECT_PROFILE; 

    case 'a':
        return ADD_PROFILE; 

    case 'p':
        return SHOW_ALL_PROFILES;
    
    case 'h':
        return HELP;  

    case 'e':
        return EXIT;
    
    default:
        return BACK;
    }

    return BACK;
}

int act_selectProfile()
{
    printString("\nSearch Profile 🔍\n");
    printString(" -- Enter First Name: ");
    char* name = getString();
    printString(" -- Enter ID: ");
    char* id = getString();

    int output = selectProfile(name, id);
    free(name);
    free(id);

    if (output == -1)
    {
        printString("\nProfile Wasn't Found... ❌\n");
        printString("\n -- Search Again? (y/n)\n");
        char key = getKey();

        switch (key)
        {
        case 'y':
            return SELECT_PROFILE;

        default:
            return BACK;
        }
    }

    printString("\nFound And Selected! ✅\n");
    return PROFILE_MENU;
}

int act_addProfile()
{
    printString("\nAdd Profile 🆕\n");
    printString(" -- Enter First Name: ");
    char* name = getString();
    printString(" -- Enter Last Name: ");
    char* lastName = getString();
    printString(" -- Enter ID: ");
    char* id = getString();

    struct Profile *p = malloc(sizeof(struct Profile));
    assert(p);

    p->name = malloc(strlen(name) + 1);
    p->lastName = malloc(strlen(lastName) + 1);
    p->id = malloc(strlen(id) + 1);
    memcpy(p->name, name, strlen(name) + 1);  // +1 for the null-terminator
    memcpy(p->lastName, lastName, strlen(lastName) + 1);
    memcpy(p->id, id, strlen(id) + 1);

    saveToStorage(p);

    free(name);
    free(lastName);
    free(id);

    printString("\nProfile Added Successfully! ✅\n");

    return BACK;
}

int act_deleteProfile()
{
    return BACK;
}

int act_editProfile()
{
    return PROFILE_MENU;
}

int act_showAllProfiles()
{
    printString("\nAll Profiles\n");
    printString(" -- Start -- \n");
    printAllProfiles();
    printString("\n -- End -- \n");
    return ALL_PROFILES_ACTIONS;
}

int act_showSelectedProfile()
{
    printSelectedProfile();
    return PROFILE_MENU;
}

int act_help()
{
    return BACK;
}

int act_profileMenu()
{
    printString("\nCurrent Profile Menu 👤\n");
    printString(" -- Print: p\n");
    printString(" -- Edit: e\n");
    printString(" -- Delete: d\n");
    printString(" -- Back: b\n");

    char key = getKey();

    switch (key)
    {
    case 'p':
        return SHOW_SELECTED_PROFILE;
    
    case 'e':
        return EDIT_PROFILE;

    case 'd':
        return DELETE_PROFILE;

    case 'b':
        return BACK;

    default:
        break;
    }

    printString("\nInvalid Input ❌\n");
    return PROFILE_MENU;
}

int act_allProfilesActions()
{
    printString("\nAll Profiles Menu 👥\n");
    printString(" -- Select Profile: s\n");
    printString(" -- Back: b\n");
    char key = getKey();

    switch (key)
    {
    case 's':
        return SELECT_PROFILE;
    
    case 'b':
        return BACK;

    default:
        break;
    }

    printString("\nInvalid Input ❌\n");
    return ALL_PROFILES_ACTIONS;
}
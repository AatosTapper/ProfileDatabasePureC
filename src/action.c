
#include "action.h"

lastAction = BACK;

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

    lastAction = BACK;
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

    lastAction = SELECT_PROFILE;
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
    printString(" -- Enter Birthday: ");
    char* bd = getString();
    printString(" -- Enter Personality: ");
    char* personality = getString();
    printString(" -- Enter Speciality: ");
    char* speciality = getString();
    printString(" -- Enter Description: ");
    char* description = getString();

    struct Profile *p = malloc(sizeof(struct Profile));
    assert(p);

    p->name = malloc(strlen(name) + 1);
    p->lastName = malloc(strlen(lastName) + 1);
    p->id = malloc(strlen(id) + 1);
    p->birthday = malloc(strlen(bd) + 1);
    p->personality = malloc(strlen(personality) + 1);
    p->speciality = malloc(strlen(speciality) + 1);
    p->description = malloc(strlen(description) + 1);
    memcpy(p->name, name, strlen(name) + 1);
    memcpy(p->lastName, lastName, strlen(lastName) + 1);
    memcpy(p->id, id, strlen(id) + 1);
    memcpy(p->birthday, bd, strlen(bd) + 1);
    memcpy(p->personality, personality, strlen(personality) + 1);
    memcpy(p->speciality, speciality, strlen(speciality) + 1);
    memcpy(p->description, description, strlen(description) + 1);

    free(name);
    free(lastName);
    free(id);
    free(bd);
    free(personality);
    free(speciality);
    free(description);

    saveToStorage(p);

    printString("\nProfile Added Successfully! ✅\n");

    lastAction = ADD_PROFILE;
    return BACK;
}

int act_deleteProfile()
{
    lastAction = DELETE_PROFILE;
    return BACK;
}

int act_editProfile()
{
    lastAction = EDIT_PROFILE;

    printString("\nEdit Profile\n");
    printString(" -- Change First Name: f\n");
    printString(" -- Change Last Name: l\n");
    printString(" -- Change ID: i\n");
    printString(" -- Change Birthday: d\n");
    printString(" -- Change Personality: p\n");
    printString(" -- Change Speciality: s\n");
    printString(" -- Back: b\n");

    char key = getKey();

    lastAction = EDIT_PROFILE;
    switch (key)
    {
    case 'f':
        return CHANGE_PROFILE_NAME;

    case 'l':
        return CHANGE_PROFILE_LAST_NAME;

    case 'i':
        return CHANGE_PROFILE_ID;
        
    case 'd':
        return CHANGE_PROFILE_BIRTHDAY;

    case 'p':
        return CHANGE_PROFILE_PERSONALITY;

    case 's':
        return CHANGE_PROFILE_SPECIALITY;

    case 'e':
        return CHANGE_PROFILE_DESCRIPTION;

    case 'b':
        return BACK;
    
    default:
        printf("\nNot a valid input... ❌\n");
        return EDIT_PROFILE;
        break;
    }

    return PROFILE_MENU;
}

int act_showAllProfiles()
{
    printString("\nAll Profiles\n");
    printString(" -- Start -- \n");
    printAllProfiles();
    printString("\n -- End -- \n");
    lastAction = SHOW_ALL_PROFILES;
    return ALL_PROFILES_MENU;
}

int act_showSelectedProfile()
{
    printSelectedProfile();
    lastAction = SHOW_SELECTED_PROFILE;
    return PROFILE_MENU;
}

int act_help()
{
    lastAction = HELP;
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

    lastAction = PROFILE_MENU;
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

int act_allProfilesMenu()
{
    printString("\nAll Profiles Menu 👥\n");
    printString(" -- Select Profile: s\n");
    printString(" -- Back: b\n");
    char key = getKey();

    lastAction = ALL_PROFILES_MENU;
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
    return ALL_PROFILES_MENU;
}

int act_changeProfileName()
{
    printString("\nNew First Name: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->name);
    sp->name = malloc(strlen(new) + 1);
    memcpy(sp->name, new, strlen(new) + 1);

    printf("\n\nChanged First Name To: %s\n", sp->name);

    return EDIT_PROFILE;
}

int act_changeProfileLastName()
{
    printString("\nNew Last Name: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->lastName);
    sp->lastName = malloc(strlen(new) + 1);
    memcpy(sp->lastName, new, strlen(new) + 1);

    printf("\n\nChanged Last Name To: %s\n", sp->lastName);

    return EDIT_PROFILE;
}

int act_changeProfileId()
{
    printString("\nNew ID: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->id);
    sp->id = malloc(strlen(new) + 1);
    memcpy(sp->id, new, strlen(new) + 1);

    printf("\n\nChanged ID To: %s\n", sp->id);

    return EDIT_PROFILE;
}

int act_changeProfileBirthday()
{
    printString("\nNew Birthday: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->birthday);
    sp->birthday = malloc(strlen(new) + 1);
    memcpy(sp->birthday, new, strlen(new) + 1);

    printf("\n\nChanged Birthday To: %s\n", sp->personality);

    return EDIT_PROFILE;
}

int act_changeProfilePersonality()
{
    printString("\nNew Personality: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->personality);
    sp->personality = malloc(strlen(new) + 1);
    memcpy(sp->personality, new, strlen(new) + 1);

    printf("\n\nChanged Personality To: %s\n", sp->personality);

    return EDIT_PROFILE;
}

int act_changeProfileSpeciality()
{
    printString("\nNew Speciality: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->speciality);
    sp->speciality = malloc(strlen(new) + 1);
    memcpy(sp->speciality, new, strlen(new) + 1);

    printf("\n\nChanged Speciality To: %s\n", sp->speciality);

    return EDIT_PROFILE;
}

int act_changeProfileDescription()
{
    printString("\nNew Description: ");
    char* new = getString();
    struct Profile* sp = getSelectedProfile();
    free(sp->description);
    sp->description = malloc(strlen(new) + 1);
    memcpy(sp->description, new, strlen(new) + 1);

    printf("\n\nChanged Description To: %s\n", sp->speciality);

    return EDIT_PROFILE;
}
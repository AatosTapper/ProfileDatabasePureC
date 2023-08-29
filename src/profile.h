
#ifndef PROFILE_H
#define PROFILE_H

#define P_SIZE 7
#define MAX_LINE 128

struct Profile
{
    char* name;
    char* lastName;
    char* id;
    char* birthday;
    char* personality;
    char* speciality;
    char* description;
};

#endif
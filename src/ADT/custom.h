/* File: custom.h */

#ifndef CUSTOM_H
#define CUSTOM_H

#include "boolean.h"
#include "list.h"

#define MAX_LEN 100
#define MAX_USERS 50

#define integer int


typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    integer money;
} User;

typedef struct {
    char name[MAX_LEN];
    integer price;
} Barang;

extern int currentUserCount ;
extern int currentLoggedInUser;


int checkUsernameExists(const char *username, List user);
int compareStrings(const char *str1, const char *str2);

#endif
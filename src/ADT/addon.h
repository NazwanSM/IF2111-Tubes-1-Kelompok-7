#ifndef ADDON_H
#define ADDON_H

#include "mesinkata.h"
#include "mesinkarakter.h"
#include "custom.h"
#include "boolean.h"
#include "list.h"

#define MAX_USERS 50

int checkUsernameExists(const char *username, List user, int nUser);
int compareStrings(const char *str1, const char *str2);

#endif
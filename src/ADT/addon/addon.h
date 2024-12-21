#ifndef ADDON_H
#define ADDON_H

#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../custom/custom.h"
#include "../boolean/boolean.h"
#include "../list/list.h"

#define MAX_USERS 50

int checkUsernameExists(const char *username, List user, int nUser);
int compareStrings(const char *str1, const char *str2);
boolean startsWith(Word w, char* prefix);
void trimString(char *str);

#endif
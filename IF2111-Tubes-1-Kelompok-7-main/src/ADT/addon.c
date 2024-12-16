#include "addon.h"


int checkUsernameExists(const char *username, List user, int nUser) {

    for (int i = 0; i < nUser; i++) {
        if (compareStrings(user.A[i].name, username)) {
            return 1;
        }
    }
    return 0;
}

int compareStrings(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    return str1[i] == str2[i];
}
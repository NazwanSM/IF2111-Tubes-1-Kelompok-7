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

boolean startsWith(Word w, char* prefix) {
    int prefixLen = 0;

    while (prefix[prefixLen] != '\0') {
        prefixLen++;
    }

    if (w.Length < prefixLen) return false;

    for (int i = 0; i < prefixLen; i++) {
        if (w.TabWord[i] != prefix[i]) return false;
    }

    return true;
}

void trimString(char *str) {
    int start = 0, end = 0;
    
    while (str[start] == ' ' || str[start] == '-' || str[start] == ',') {
        start++;
    }
    
    end = start;
    while (str[end] != '\0') {
        end++;
    }
    end--;
    while (end >= start && (str[end] == ' ' || str[end] == '-' || str[end] == ',')) {
        end--;
    }
    
    int i;
    for (i = 0; start <= end; start++, i++) {
        str[i] = str[start];
    }
    str[i] = '\0';
}

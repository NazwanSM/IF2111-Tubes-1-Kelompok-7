#include <stdio.h>
#include "login.h"

// Handle user login process
int loginUser(List user, int nUser) {
    
    printf("Username: ");
    STARTWORD();
    char username[MAX_LEN] = {0};
    int usernameLen = 0;
    
    for (int i = 0; i < CurrentWord.Length; i++) {
        username[i] = CurrentWord.TabWord[i];
    }
    usernameLen = CurrentWord.Length;
    username[usernameLen] = '\0';

    int userIdx = -1;
    for (int i = 0; i < nUser; i++) {
        if (compareStrings(user.A[i].name, username)) {
            userIdx = i;
            break;
        }
    }


    printf("Password: ");
    STARTWORD();
    char password[MAX_LEN] = {0};
    int passwordLen = 0;
    

    for (int i = 0; i < CurrentWord.Length; i++) {
        password[i] = CurrentWord.TabWord[i];
    }
    passwordLen = CurrentWord.Length;
    password[passwordLen] = '\0';

    if (userIdx == -1 || !compareStrings(user.A[userIdx].password, password)) {
        printf(COLOR_BOLD_RED"\nUsername atau password salah.\n"COLOR_OFF);
        return -1;
    }
    else {
        printf(COLOR_BOLD"\nAnda telah login ke "COLOR_OFF COLOR_BOLD_YELLOW"PURR"COLOR_OFF COLOR_CYAN"MART"COLOR_OFF COLOR_BOLD" sebagai "COLOR_OFF COLOR_BOLD_BLUE"%s.\n"COLOR_OFF, username);
        return userIdx;
    }
}
#include <stdio.h>
#include "login.h"




// Handle user login process
int loginUser(List user, int nUser) {
    
    printf("Username: ");
    START();
    char username[MAX_LEN] = {0};
    int usernameLen = 0;
    
    while (currentChar != MARK && usernameLen < MAX_LEN - 1) {
        username[usernameLen++] = currentChar;
        ADV();
    }
    username[usernameLen] = '\0';

    int userIdx = -1;
    for (int i = 0; i < nUser; i++) {
        if (compareStrings(user.A[i].name, username)) {
            userIdx = i;
            break;
        }
    }


    printf("Password: ");
    START();
    char password[MAX_LEN] = {0};
    int passwordLen = 0;
    

    while (currentChar != MARK && passwordLen < MAX_LEN - 1) {
        password[passwordLen++] = currentChar;
        ADV();
    }
    password[passwordLen] = '\0';


    if (userIdx == -1 || !compareStrings(user.A[userIdx].password, password)) {
        printf("Username atau password salah.\n");
        return 0;
    }
    else {
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        return userIdx;
    }
}


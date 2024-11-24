#include <stdio.h>
#include "register.h"




// Register a new user in the system
void addUser(List *user, int *nUser) {
    
    if (*nUser >= MAX_USERS) {
        return;
    }

    
    char username[MAX_LEN] = {0};
    int usernameLen = 0;
    boolean validUsername = false;
    
    while (!validUsername) {
        printf("Username: ");
        START();
        usernameLen = 0;
        
        while (currentChar != MARK && usernameLen < MAX_LEN - 1) {
            username[usernameLen++] = currentChar;
            ADV();
        }

        username[usernameLen] = '\0';

        if (usernameLen == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
            continue;
        }
        
        if (checkUsernameExists(username, *user)) {
            printf("Username %s sudah digunakan. Silakan gunakan username lain.\n", username);
            continue;
        }
        
        validUsername = true;
    }

    for (int i = 0; i <= usernameLen; i++) {
        user->A[*nUser].name[i] = username[i];
    }


    char password[MAX_LEN] = {0};
    int passwordLen = 0;


    printf("Password: ");
    START();
    while (currentChar != MARK && passwordLen < MAX_LEN - 1) {
        password[passwordLen++] = currentChar;
        ADV();
    }
    password[passwordLen] = '\0';

    for (int i = 0; i <= passwordLen; i++) {
        user->A[*nUser].password[i] = password[i];
    }

    user->A[*nUser].money = 0;
    (*nUser)++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}
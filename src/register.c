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
        STARTWORD();
        usernameLen = 0;
        
        for (int i = 0; i < CurrentWord.Length; i++) {
        username[i] = CurrentWord.TabWord[i];
        }
        username[CurrentWord.Length] = '\0';
        usernameLen = CurrentWord.Length;

        if (usernameLen == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
            continue;
        }
        
        if (checkUsernameExists(username, *user, *nUser)) {
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
    STARTWORD();
    for (int i = 0; i < CurrentWord.Length; i++) {
        password[i] = CurrentWord.TabWord[i];
    }
    password[CurrentWord.Length] = '\0';
    passwordLen = CurrentWord.Length;

    for (int i = 0; i <= passwordLen; i++) {
        user->A[*nUser].password[i] = password[i];
    }

    user->A[*nUser].money = 0;
    Top(user->A[*nUser].riwayat_pembelian) = NilS;
    user->A[*nUser].keranjang.Count = NilM;
    First(user->A[*nUser].wishlist) = Nil;
    (*nUser)++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}
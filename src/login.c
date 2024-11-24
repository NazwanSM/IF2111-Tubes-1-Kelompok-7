#include <stdio.h>
#include "login.h"




// Handle user login process
int loginUser() {
    // Check if another user is already logged in
    if (currentLoggedInUser != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", 
               users[currentLoggedInUser].username);
        return 0;
    }

    // Get username input
    printf("Username: ");
    START();
    char username[MAX_LENGTH] = {0};
    int usernameLen = 0;
    
    // Read username character by character
    while (currentChar != MARK && usernameLen < MAX_LENGTH - 1) {
        username[usernameLen++] = currentChar;
        ADV();
    }
    username[usernameLen] = '\0';

    // Search for user in the system
    int userIndex = -1;
    for (int i = 0; i < currentUserCount; i++) {
        if (compareStrings(users[i].username, username)) {
            userIndex = i;
            break;
        }
    }

    // Get password input
    printf("Password: ");
    START();
    char password[MAX_LENGTH] = {0};
    int passwordLen = 0;
    
    // Read password character by character
    while (currentChar != MARK && passwordLen < MAX_LENGTH - 1) {
        password[passwordLen++] = currentChar;
        ADV();
    }
    password[passwordLen] = '\0';

    // Validate credentials
    if (userIndex == -1 || !compareStrings(users[userIndex].password, password)) {
        printf("Username atau password salah.\n");
        return 0;
    }

    // Set user as logged in
    users[userIndex].isLoggedIn = 1;
    currentLoggedInUser = userIndex;
    printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    return userIndex;
}


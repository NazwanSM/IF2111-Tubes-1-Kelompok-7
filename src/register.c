#include <stdio.h>
#include "register.h"




// Register a new user in the system
int addUser() {
    // Check if user limit is reached
    if (currentUserCount >= MAX_USERS) {
        return 0;
    }

    // Buffer for storing username input
    char username[MAX_LENGTH] = {0};
    // Track length of entered username
    int usernameLen = 0;
    // Flag to control username validation loop
    boolean validUsername = false;
    
    // Keep asking for username until valid
    while (!validUsername) {
        // Prompt for username input
        printf("Username: ");
        // Initialize input reading
        START();
        // Reset username length
        usernameLen = 0;
        
        // Read username character by character
        while (currentChar != MARK && usernameLen < MAX_LENGTH - 1) {
            username[usernameLen++] = currentChar;
            ADV();
        }
        // Null-terminate the username string
        username[usernameLen] = '\0';

        // Validate username is not empty
        if (usernameLen == 0) {
            printf("Username tidak boleh kosong. Silakan coba lagi.\n");
            continue;
        }
        
        // Check if username is already taken
        if (checkUsernameExists(username)) {
            printf("Username %s sudah digunakan. Silakan gunakan username lain.\n", username);
            continue;
        }
        
        // Username is valid
        validUsername = true;
    }

    // Copy validated username to users array
    for (int i = 0; i <= usernameLen; i++) {
        users[currentUserCount].username[i] = username[i];
    }

    // Buffer for storing password
    char password[MAX_LENGTH] = {0};
    // Track length of entered password
    int passwordLen = 0;

    // Get password input
    printf("Password: ");
    START();
    // Read password character by character
    while (currentChar != MARK && passwordLen < MAX_LENGTH - 1) {
        password[passwordLen++] = currentChar;
        ADV();
    }
    // Null-terminate the password string
    password[passwordLen] = '\0';

    // Copy password to users array
    for (int i = 0; i <= passwordLen; i++) {
        users[currentUserCount].password[i] = password[i];
    }

    // Initialize login status
    users[currentUserCount].isLoggedIn = 0;
    users[currentUserCount].money = 0;  // Set initial money to 0
    // Increment user count
    currentUserCount++;
    // Display success message
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    return 1;
}
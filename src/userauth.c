// Header files for standard I/O and custom functionality
#include <stdio.h>
#include "userauth.h"


// Global array to store all user information
User users[MAX_USERS];
// Counter to track total number of registered users
int currentUserCount = 0;
// Index of currently logged in user (-1 means no user logged in)
int currentLoggedInUser = -1;

// Initialize the user system to its default state
void initUsers() {
    // Reset user count to zero
    currentUserCount = 0;
    // Reset logged in user to none
    currentLoggedInUser = -1;
}


// Compare two strings for equality
int compareStrings(const char *str1, const char *str2) {
    int i = 0;
    // Compare characters until end of either string
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    // Ensure both strings ended
    return str1[i] == str2[i];


/*
If you compare "hi" with "high"
It checks 'h'='h', 'i'='i'
One string ends while the other continues
Returns 0 (false) because lengths are different

return 0 means FALSE or failure
return 1 means TRUE or success
*/
}

// Convert string to integer
int stringToInt(char *str) {
    // Initialize result
    int num = 0;
    int i = 0;
    // Process each digit
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

/*
// Load user data from file
void loadUsers() {
    // Reset user count
    currentUserCount = 0;
    
    // Open file for reading
    FILE *file = fopen("src/users.txt", "r");
    if (file == NULL) {
        printf("Failed to open users.txt\n");
        return;
    }

    // Read number of users
    int numUsers;
    fscanf(file, "%d\n", &numUsers);

    // Read each user's data
    char username[MAX_LENGTH], password[MAX_LENGTH];
    int money;
    while (currentUserCount < numUsers && 
           fscanf(file, "%[^,],%[^,],%d\n", username, password, &money) == 3) {
        
        // Copy username
        int i = 0;
        while (username[i] != '\0') {
            users[currentUserCount].username[i] = username[i];
            i++;
        }
        users[currentUserCount].username[i] = '\0';
        
        // Copy password
        i = 0;
        while (password[i] != '\0') {
            users[currentUserCount].password[i] = password[i];
            i++;
        }
        users[currentUserCount].password[i] = '\0';
        
        // Initialize login status
        users[currentUserCount].money = money;
        users[currentUserCount].isLoggedIn = 0;
        currentUserCount++;
    }

    // Close file and confirm
    fclose(file);
    printf("Successfully loaded %d users\n", currentUserCount);
}
*/


// Check if username already exists in system
int checkUsernameExists(const char *username) {
    // Check against all existing users
    for (int i = 0; i < currentUserCount; i++) {
        if (compareStrings(users[i].username, username)) {
            return 1;
        }
    }
    return 0;
}


/* 
// Handle user logout process
void logoutUser() {
    // Check if any user is logged in
    if (currentLoggedInUser == -1) {
        printf("Anda belum login.\n");
        return;
    }
    
    // Set user as logged out
    users[currentLoggedInUser].isLoggedIn = 0;
    printf("Anda telah logout dari PURRMART.\n");
    currentLoggedInUser = -1;
}


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
    // Increment user count
    currentUserCount++;
    // Display success message
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    return 1;
}

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
    return 1;
}

void saveUsers() {
    // Open file for writing
    FILE *file = fopen("src/users.txt", "w");
    if (file == NULL) {
        printf("Gagal menyimpan data pengguna.\n");
        return;
    }

    // Write number of users
    fprintf(file, "%d\n", currentUserCount);
    
    // Write each user's data
    for (int i = 0; i < currentUserCount; i++) {
        fprintf(file, "%s,%s,%d\n", users[i].username, users[i].password, users[i].money);
    }
    
    // Close file and confirm
    fclose(file);
    printf("Berhasil menyimpan data pengguna.\n");
}

*/
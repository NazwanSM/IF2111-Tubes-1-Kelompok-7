#ifndef __USERAUTH_H__
#define __USERAUTH_H__

#include "ADT/mesinkata_login.h"
#include "ADT/mesinkarakter_login.h"
#include "ADT/boolean.h"

// Constants
#define MAX_USERS 100 // The maximum number of users we can store (100 in this case).
#define MAX_LENGTH 50 // The maximum length of a username or password (50 characters in this case).

// Structure to store user data
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int isLoggedIn;
    int money;
} User;

// External variables == global variable
extern User users[MAX_USERS];
extern int currentUserCount ; // Tracks the current number of registered users.
extern int currentLoggedInUser; // -1 if no user is logged

// Function prototypes for registering and logging in users
void initUsers();
int addUser();
int loginUser();
int compareStrings(const char *str1, const char *str2);
void printUsers();
int stringToInt(char *str);
void logoutUser();
//void saveUsers();
//void loadUsers();
int checkUsernameExists(const char* username);


#endif
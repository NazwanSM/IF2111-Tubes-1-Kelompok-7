#include <stdio.h>
#include "userauth.h"
#include "logout.h"



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
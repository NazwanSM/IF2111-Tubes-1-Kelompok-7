#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

void displayPurrMart() {
    printf("\033[1;33m"); 
    printf(" ######  ##  ## ######  ######  ##   ##  ######  ######  ######\n");
    printf(" ##  ##  ##  ## ##  #   ##  #   ### ###  ##  ##  ##  #     ##  \n");
    printf(" ######  ##  ## ######  ######  ## # ##  ######  ######    ##  \n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf(" ##      ##  ## ##  ##  ##  ##  ##   ##  ##  ##  ##  ##    ##  \n");
    printf(" ##       ####  ##  ##  ##  ##  ##   ##  ##  ##  ##  ##    ##  \n");
    printf("\033[0m");
}

void displayWelcomeMenu() {
    printf("\n\033[1;33mWELCOME TO PURRMART!\033[0m\n\n");
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}

void displayLoginMenu() {
    printf("\n\033[1;33mLOGIN OR SIGNUP TO YOUR ACCOUNT!\033[0m\n\n");
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1. REGISTER\n");
    printf("2. LOGIN\n");
    printf("3. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}

void displayMainMenu(List user, int userIdx) {
    printf("\n\033[1;33mWELCOME TO MAIN MENU\033[0m\n\n");
    printf("\033[1;32mUsername: %s\033[0m\n", user.A[userIdx].name);
    printf("\033[1;32mMoney: %d\033[0m\n\n", user.A[userIdx].money);
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1. WORK\n");
    printf("2. WORK CHALLENGE\n");
    printf("3. STORE LIST\n");
    printf("4. STORE REQUEST\n");
    printf("5. STORE SUPPLY\n");
    printf("6. STORE REMOVE\n");
    printf("7. LOGOUT\n");
    printf("8. SAVE\n");
    printf("9. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}
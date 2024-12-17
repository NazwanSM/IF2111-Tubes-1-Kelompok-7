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
    printf("\033[1;34mLoad file bisa langsung dipanggil dengan mendouble huruf\033[0m\n");
    printf("\033[1;34mpertamanya (contoh: LOAD ssave.txt)\033[0m\n\n");
}

void displayLoginMenu() {
    printf("\n\033[1;33mLOGIN OR SIGNUP TO YOUR ACCOUNT!\033[0m\n\n");
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1. REGISTER\n");
    printf("2. LOGIN\n");
    printf("3. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}

void displayMainMenu() {
    printf("\n\033[1;33mWELCOME TO MAIN MENU\033[0m\n\n");
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1.  PROFILE\n");
    printf("2.  WORK\n");
    printf("3.  WORK CHALLENGE\n");
    printf("4.  STORE LIST\n");
    printf("5.  STORE REQUEST\n");
    printf("6.  STORE SUPPLY\n");
    printf("7.  STORE REMOVE\n");
    printf("8.  CART ADD\n");
    printf("9.  CART REMOVE\n");
    printf("10. CART SHOW\n");
    printf("11. CART PAY\n");
    printf("12. HISTORY\n");
    printf("13. LOGOUT\n");
    printf("14. SAVE\n");
    printf("15. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}
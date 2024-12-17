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
    printf(COLOR_BOLD_BLUE "PILIHAN MENU:\n" COLOR_OFF);
    printf("\033[1;33m1.\033[0m  PROFILE\n");
    printf("\033[1;33m2.\033[0m  WORK\n");
    printf("\033[1;33m3.\033[0m  WORK CHALLENGE\n");
    printf("\033[1;33m4.\033[0m  STORE LIST\n");
    printf("\033[1;33m5.\033[0m  STORE REQUEST\n");
    printf("\033[1;33m6.\033[0m  STORE SUPPLY\n");
    printf("\033[1;33m7.\033[0m  STORE REMOVE\n");
    printf("\033[1;33m8.\033[0m  CART ADD <nama> <n>\n");
    printf("\033[1;33m9.\033[0m  CART REMOVE\n");
    printf("\033[1;33m10.\033[0m CART SHOW\n");
    printf("\033[1;33m11.\033[0m HISTORY <n>\n");
    printf("\033[1;33m12.\033[0m LOGOUT\n");
    printf("\033[1;33m13.\033[0m SAVE\n");
    printf("\033[1;33m14.\033[0m QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}
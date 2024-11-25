#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/ADT/arraydin.h"
#include "src/ADT/list.h"
#include "src/ADT/readTxt.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/custom.h"
#include "src/ADT/boolean.h"
#include "src/ADT/queue.h"
#include "src/start.h"
#include "src/work.h"
#include "src/work_challenge.h"
#include "src/load.h"
#include "src/save.h"
#include "src/help.h"
#include "src/quit.h"
#include "src/register.h"
#include "src/login.h"
#include "src/logout.h"
#include "src/storeList.h"
#include "src/storeRequest.h"
#include "src/storeSupply.h"
#include "src/storeRemove.h"

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

void displayMainMenu() {
    printf("\n\033[1;33mWELCOME TO MAIN MENU\033[0m\n\n");
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

int main() {
    int nBarang = 0;
    int nUser = 0;
    int userIdx = -1;
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    Queue antrian;
    CreateQueue(&antrian);

    boolean loaded = false; // untuk start dan load
    boolean loggedIn = false; // untuk login
    boolean change = false; // untuk save 

    while(true){
        while (!loaded){
            system("cls || clear");
            displayPurrMart();
            displayWelcomeMenu();
            printf("\033[1;34mMasukkan perintah Anda: \033[0m");
            STARTWORD();
            Word choice = CurrentWord;

            if (isKataSama(choice, "START")) {
                printf("\n\033[1;34m>> START\033[0m\n");
                start("../save/config.txt", &barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loaded = true;
            }
            else if (isKataSama(choice, "LOAD")) {
                printf("\n\033[1;34m>> LOAD\033[0m\n");
                loadcheck(&barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loaded = true;
            }
            else if (isKataSama(choice, "QUIT")) {
                printf("\n\033[1;34m>> QUIT\033[0m\n");
                quit(barang, user, nBarang, nUser, change);
            }
            else if (isKataSama(choice, "HELP")) {
                printf("\n\033[1;34m>> HELP\033[0m\n");
                help1();

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else {
                printf("Menu tidak valid, silahkan coba lagi\n");

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
        }

        while(!loggedIn){
            system("cls || clear");
            displayPurrMart();
            displayLoginMenu();
            printf("\033[1;34mMasukkan perintah Anda: \033[0m");
            STARTWORD();
            Word choice = CurrentWord;

            if (isKataSama(choice, "REGISTER")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> REGISTER\033[0m\n");
                addUser(&user, &nUser);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "LOGIN")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> LOGIN\033[0m\n");
                userIdx = loginUser(user, nUser);

                if (userIdx != -1) {
                    struct timespec req = {2, 0};
                    nanosleep(&req, NULL);
                    loggedIn = true;
                    break;
                }

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "QUIT")) {
                if (change){
                    system("cls || clear");
                    displayPurrMart();
                    printf("\n\033[1;34m>> QUIT\033[0m\n");
                    quit(barang, user, nBarang, nUser, change);
                }
                else {
                    printf("\n\033[1;34m>> QUIT\033[0m\n");
                    quit(barang, user, nBarang, nUser, change);
                }
            }
            else if (isKataSama(choice, "HELP")) {
                printf("\n\033[1;34m>> HELP\033[0m\n");
                help2();

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else {
                printf("Menu tidak valid, silahkan coba lagi\n");

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
        }
        
        while(loggedIn){
            system("cls || clear");
            displayPurrMart();
            displayMainMenu();
            printf("\033[1;34mMasukkan perintah Anda: \033[0m");
            STARTWORD();
            Word choice = CurrentWord;

            while (currentChar != '\n'){
            ADVWORD();
            choice.TabWord[choice.Length] = ' ';
            choice.Length++;
        
            for (int i = 0; i < CurrentWord.Length; i++){
                choice.TabWord[choice.Length] = CurrentWord.TabWord[i];
                choice.Length++;
            }
    }

            if (isKataSama(choice, "WORK")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> WORK\033[0m\n\n");
                work(&user, userIdx);
                change = true;

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WORK CHALLENGE")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> WORK CHALLENGE\033[0m\n\n");
                work_challenge(&user, userIdx);
                change = true;

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE LIST")) {
                printf("\n\033[1;34m>> STORE LIST\033[0m\n\n");
                storeList(barang, nBarang);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE REQUEST")) {
                printf("\n\033[1;34m>> STORE REQUEST\033[0m\n\n");
                storeRequest(&barang, &antrian);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE SUPPLY")) {
                printf("\n\033[1;34m>> STORE SUPPLY\033[0m\n\n");
                storesupply(&barang, &antrian, &nBarang);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE REMOVE")) {
                printf("\n\033[1;34m>> STORE REMOVE\033[0m\n\n");
                storeremove(&barang, &nBarang);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "LOGOUT")) {
                printf("\n\033[1;34m>> LOGOUT\033[0m\n\n");
                logoutUser(&userIdx, user);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loggedIn = false;
            }
            else if (isKataSama(choice, "SAVE")) {
                printf("\n\033[1;34m>> SAVE\033[0m\n\n");
                save(barang, user, nBarang, nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "QUIT")) {
                if (change){
                    system("cls || clear");
                    displayPurrMart();
                    printf("\n\033[1;34m>> QUIT\033[0m\n");
                    quit(barang, user, nBarang, nUser, change);
                }
                else {
                    printf("\n\033[1;34m>> QUIT\033[0m\n");
                    quit(barang, user, nBarang, nUser, change);
                }
            }
            else if (isKataSama(choice, "HELP")) {
                printf("\n\033[1;34m>> HELP\033[0m\n");
                help3();

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else {
                printf("Menu tidak valid, silahkan coba lagi\n");

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

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
            printf(COLOR_BOLD_BLUE"Masukkan perintah Anda: "COLOR_OFF);
            STARTWORD();
            Word choice = CurrentWord;

            if (isKataSama(choice, "START")) {
                start("../save/config.txt", &barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loaded = true;
            }
            else if (startsWith(choice, "LOAD")) {
                printf(COLOR_BOLD_CYAN"\n>> LOAD\033[0m ");               
                load(&barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                if (nUser > 0){
                    loaded = true;
                }
            }
            else if (isKataSama(choice, "QUIT")) {
                printf(COLOR_BOLD_CYAN"\n>> QUIT\n\n"COLOR_OFF);
                quit(barang, user, nBarang, nUser, change);
            } 
            else if (isKataSama(choice, "HELP")) {
                printf(COLOR_BOLD_CYAN"\n>> HELP\n\n"COLOR_OFF);
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
            printf(COLOR_BOLD_BLUE"Masukkan perintah Anda: "COLOR_OFF);
            STARTWORD();
            Word choice = CurrentWord;

            if (isKataSama(choice, "REGISTER")) {
                system("cls || clear");
                displayPurrMart();
                printf(COLOR_BOLD_CYAN"\n>> REGISTER\n\n"COLOR_OFF);
                addUser(&user, &nUser);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "LOGIN")) {
                system("cls || clear");
                displayPurrMart();
                printf(COLOR_BOLD_CYAN"\n>> LOGIN\n\n"COLOR_OFF);
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
                    printf(COLOR_BOLD_CYAN"\n>> QUIT\n\n"COLOR_OFF);
                    quit(barang, user, nBarang, nUser, change);
                }
                else {
                    printf(COLOR_BOLD_CYAN"\n>> QUIT\n\n"COLOR_OFF);
                    quit(barang, user, nBarang, nUser, change);
                }
            }
            else if (isKataSama(choice, "HELP")) {
                printf(COLOR_BOLD_CYAN"\n>> HELP\n\n"COLOR_OFF);
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
            printf(COLOR_BOLD_BLUE"Masukkan perintah Anda: "COLOR_OFF);
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

            if (isKataSama(choice, "PROFILE")) {
                system("cls || clear");
                displayPurrMart();
                printf(COLOR_BOLD_CYAN"\n>> PROFILE\033[0m\n\n");
                profile(user, userIdx);
                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }

            else if (isKataSama(choice, "WORK")) {
                system("cls || clear");
                displayPurrMart();
                printf(COLOR_BOLD_CYAN"\n>> WORK\033[0m\n\n");
                work(&user, userIdx);
                change = true;

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WORK CHALLENGE")) {
                system("cls || clear");
                displayPurrMart();
                printf(COLOR_BOLD_CYAN"\n>> WORK CHALLENGE\033[0m\n\n");
                work_challenge(&user, userIdx);
                change = true;

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE LIST")) {
                printf(COLOR_BOLD_CYAN"\n>> STORE LIST\033[0m\n\n");
                storeList(barang, nBarang);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE REQUEST")) {
                printf(COLOR_BOLD_CYAN"\n>> STORE REQUEST\033[0m\n\n");
                storeRequest(&barang, &antrian);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE SUPPLY")) {
                printf(COLOR_BOLD_CYAN"\n>> STORE SUPPLY\033[0m\n\n");
                storesupply(&barang, &antrian, &nBarang);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "STORE REMOVE")) {
                printf(COLOR_BOLD_CYAN"\n>> STORE REMOVE\033[0m\n\n");
                storeremove(&barang, &nBarang);
                change = true;

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (startsWith(choice, "CART ADD")) {
                int i = 9;
                char namaBarang[MAX_LEN];
                int namaLength = 0;
                int jumlah = 0;
                
                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }
                
                int lastSpacePos = -1;
                for (int j = choice.Length - 1; j >= i; j--) {
                    if (choice.TabWord[j] == ' ') {
                        if (j + 1 < choice.Length && 
                            choice.TabWord[j + 1] >= '0' && 
                            choice.TabWord[j + 1] <= '9') {
                            lastSpacePos = j;
                            break;
                        }
                    }
                }
                
                if (lastSpacePos != -1) {
                    for (int j = i; j < lastSpacePos; j++) {
                        namaBarang[namaLength] = choice.TabWord[j];
                        namaLength++;
                    }
                    namaBarang[namaLength] = '\0';
                    
                    for (int j = lastSpacePos + 1; j < choice.Length; j++) {
                        if (choice.TabWord[j] >= '0' && choice.TabWord[j] <= '9') {
                            jumlah = jumlah * 10 + (choice.TabWord[j] - '0');
                        }
                    }
                }
                printf(COLOR_BOLD_CYAN"\n>> CART ADD %s %d\033[0m\n\n", namaBarang, jumlah);
                cartAdd(&user, userIdx, barang, namaBarang, jumlah);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "CART SHOW")) {
                printf(COLOR_BOLD_CYAN"\n>> CART SHOW\033[0m\n\n");
                cartShow(user, userIdx);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (startsWith(choice, "HISTORY")) {
                int N = 0;
                int i = 8; 
                
                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }
                
                while (i < choice.Length && choice.TabWord[i] >= '0' && choice.TabWord[i] <= '9') {
                    N = N * 10 + (choice.TabWord[i] - '0');
                    i++;
                }
                printf(COLOR_BOLD_CYAN"\n>> HISTORY %d\033[0m\n\n", N);
                displayHistory(user, userIdx, N);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "LOGOUT")) {
                printf(COLOR_BOLD_CYAN"\n>> LOGOUT\033[0m\n\n");
                logoutUser(&userIdx, user);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loggedIn = false;
            }
            else if (isKataSama(choice, "SAVE")) {
                printf(COLOR_BOLD_CYAN"\n>> SAVE\033[0m\n\n");
                save(barang, user, nBarang, nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            } 
            else if (isKataSama(choice, "QUIT")) {
                if (change){
                    system("cls || clear");
                    displayPurrMart();
                    printf(COLOR_BOLD_CYAN"\n>> QUIT\n\n"COLOR_OFF);
                    quit(barang, user, nBarang, nUser, change);
                }
                else {
                    printf(COLOR_BOLD_CYAN"\n>> QUIT\n\n"COLOR_OFF);
                    quit(barang, user, nBarang, nUser, change);
                }
            } 
            else if (isKataSama(choice, "HELP")) {
                printf(COLOR_BOLD_CYAN"\n>> HELP\n\n"COLOR_OFF);
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

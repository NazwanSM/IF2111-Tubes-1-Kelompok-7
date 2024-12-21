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
            struct timespec req = {1, 0};
            nanosleep(&req, NULL);
            displayWelcomeMenu();
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

            if (isKataSama(choice, "START")) {
                start(&barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loaded = true;
            }
            else if (startsWith(choice, "LOAD")) {
                char loadfile[100] = "save/";
                int loadfileLen = 5;
                int i = 5;
                
                // Skip any spaces after LOAD
                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }
                
                while (i < choice.Length) {
                    loadfile[loadfileLen++] = choice.TabWord[i];
                    i++;
                }
                loadfile[loadfileLen] = '\0';
                
                printf(COLOR_BOLD_CYAN"\n>> LOAD %s\033[0m\n", loadfile + 5);
                load(loadfile, &barang, &user, &nBarang, &nUser);

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

                if (lastSpacePos == -1) {
                    printf(COLOR_BOLD_CYAN"\n>> CART ADD\033[0m\n\n");
                    printf(COLOR_BOLD_RED"Gunakan format CART ADD <nama> <jumlah> \n"COLOR_OFF);
                } else {
                    printf(COLOR_BOLD_CYAN"\n>> CART ADD %s %d\033[0m\n\n", namaBarang, jumlah);
                    cartAdd(&user, userIdx, barang, namaBarang, jumlah);
                }

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (startsWith(choice, "CART REMOVE")) {
                int i = 12;
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
                if (lastSpacePos == -1) {
                    printf(COLOR_BOLD_RED"Gunakan format CART REMOVE <nama> <jumlah> \n"COLOR_OFF);
                } else {
                    printf(COLOR_BOLD_CYAN"\n>> CART REMOVE %s %d\033[0m\n\n", namaBarang, jumlah);
                    cartRemove(&user, userIdx, namaBarang, jumlah);
                }

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "CART SHOW")) {
                printf(COLOR_BOLD_CYAN"\n>> CART SHOW\033[0m\n\n");
                cartShow(user, userIdx);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if(isKataSama(choice, "CART PAY")){
                printf(COLOR_BOLD_CYAN"\n>> CART PAY\033[0m\n\n");
                cartPay(&user, userIdx, &change);

                struct timespec req = {3, 0};
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
            else if (isKataSama(choice, "WISHLIST ADD")) {
                printf("\n\033[1;34m>> WISHLIST ADD\033[0m\n");
                wishlistAdd(&user, &barang, userIdx);

                struct timespec req = {3, 0};
                nanosleep(&req, NULL);
            }

            else if (isKataSama(choice, "WISHLIST REMOVE")) {
                printf("\n\033[1;34m>> WISHLIST REMOVE\033[0m\n");
                wishlistRemove(&user, userIdx);

                struct timespec req = {3, 0};
                nanosleep(&req, NULL);
            }
            else if (startsWith(choice, "WISHLIST SWAP")) { //ini swap <i> <j>
                int N = 0;
                int i = 14;
                int M = 0;

                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }

                while (i < choice.Length && choice.TabWord[i] >= '0' && choice.TabWord[i] <= '9') {
                    N = N * 10 + (choice.TabWord[i] - '0');
                    i++;
                }

                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }

                while (i < choice.Length && choice.TabWord[i] >= '0' && choice.TabWord[i] <= '9') {
                    M = M * 10 + (choice.TabWord[i] - '0');
                    i++;
                }
                
                printf(COLOR_BOLD_CYAN"\n>> WISHLIST SWAP %d %d\n\n"COLOR_OFF, N, M);
                wishlistSwap(&user, userIdx, N, M);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (startsWith(choice, "WISHLIST REMOVE")) { //ini harusnya remove <i>
                int N = 0;
                int i = 16;

                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }

                while (i < choice.Length && choice.TabWord[i] >= '0' && choice.TabWord[i] <= '9') {
                    N = N * 10 + (choice.TabWord[i] - '0');
                    i++;
                }

                if (1) { // ini mksdnya ngecek kalo angka ato bukan tp sementara gw giniin dulu
                    printf(COLOR_BOLD_CYAN"\n>> WISHLIST REMOVE %d\n\n"COLOR_OFF, N);
                    wishlistRemovei(&user, userIdx, N);
                } else {
                    printf(COLOR_BOLD_CYAN"\n>> WISHLIST REMOVE \n\n"COLOR_OFF);
                    printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak\n");
                }

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST CLEAR")) {
                printf(COLOR_BOLD_CYAN"\n>> WISHLIST CLEAR \n\n"COLOR_OFF);
                wishlistClear(&user, userIdx);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST SHOW")) {
                printf(COLOR_BOLD_CYAN"\n>> WISHLIST SHOW \n\n"COLOR_OFF);
                wishlistShow(user, userIdx);

                struct timespec req = {3, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "LOGOUT")) {
                printf(COLOR_BOLD_CYAN"\n>> LOGOUT\n\n"COLOR_OFF);
                logoutUser(&userIdx, user);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loggedIn = false;
            }
            else if (startsWith(choice, "SAVE")) {
                char savefile[100] = "save/";
                int savefileLen = 5;
                int i = 5;
                
                while (i < choice.Length && choice.TabWord[i] == ' ') {
                    i++;
                }
                
                while (i < choice.Length) {
                    savefile[savefileLen++] = choice.TabWord[i];
                    i++;
                }
                savefile[savefileLen] = '\0';

                printf(COLOR_BOLD_CYAN"\n>> SAVE %s\033[0m\n", savefile + 5);
                save(savefile, savefileLen, barang, user, nBarang, nUser);

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
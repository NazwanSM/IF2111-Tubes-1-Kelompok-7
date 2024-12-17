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
            printf("\033[1;34mMasukkan perintah Anda: \033[0m");
            STARTWORD();
            Word choice = CurrentWord;

            if (isKataSama(choice, "START")) {
                start("../save/config.txt", &barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                loaded = true;
            }
            else if (isKataSama(choice, "LOAD")) {
                printf("\n\033[1;34m>> LOAD\033[0m ");
                load(&barang, &user, &nBarang, &nUser);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
                if (nUser > 0){
                    loaded = true;
                }
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

            if (isKataSama(choice, "PROFILE")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> PROFILE\033[0m\n\n");
                profile(user, userIdx);
                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }

            else if (isKataSama(choice, "WORK")) {
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
            else if (isKataSama(choice, "CART ADD")) {
                system("cls || clear");
                displayPurrMart();
                printf("\n\033[1;34m>> CART ADD\033[0m\n\n");
                cartAdd(&user, userIdx, barang);

                struct timespec req = {2, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "CART SHOW")) {
                printf("\n\033[1;34m>> CART SHOW\033[0m\n\n");
                cartShow(user, userIdx);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST SWAP")) { //ini swap <i> <j>
                int N, M;
                printf("\nMasukkan nilai N dan M: ");
                scanf("%d %d", &N, &M); // buat sementara
                printf("\n\033[1;34m>> WISHLIST SWAP %d %d\033[0m\n\n", N, M);
                wishlistSwap(&user, userIdx, N, M);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST REMOVE")) { //ini harusnya remove <i>
                int N;
                printf("\nMasukkan nilai N : ");
                scanf("%d", &N);
                if (1) { // ini mksdnya ngecek kalo angka ato bukan tp sementara gw giniin dulu
                    printf("\n\033[1;34m>> WISHLIST REMOVE %d\033[0m\n\n", N);
                    wishlistRemovei(&user, userIdx, N);
                } else {
                    printf("\n\033[1;34m>> WISHLIST REMOVE \033[0m\n\n");
                    printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak\n");
                }

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST CLEAR")) {
                printf("\n\033[1;34m>> WISHLIST CLEAR \033[0m\n\n");
                wishlistClear(&user, userIdx);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "WISHLIST SHOW")) {
                printf("\n\033[1;34m>> WISHLIST SHOW \033[0m\n\n");
                wishlistShow(user, userIdx);

                struct timespec req = {4, 0};
                nanosleep(&req, NULL);
            }
            else if (isKataSama(choice, "HISTORY")) {
                int N;
                printf("\nMasukkan nilai N : ");
                scanf("%d", &N); // buat sementara
                printf("\n\033[1;34m>> HISTORY %d\033[0m\n\n", N);
                displayHistory(user, userIdx, N);

                struct timespec req = {4, 0};
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

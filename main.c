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
#include "src/start.h"
#include "src/work.h"
#include "src/work_challenge.h"
#include "src/load.h"
#include "src/save.h"
#include "src/help.h"
#include "src/quit.h"
#include "src/register.h"
#include "src/login.h"


void displayWelcome() {
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

void displatWelcomeMenu() {
    printf("\n\033[1;33mWelcome to PURRMART!\033[0m\n");
    printf("Please choose an option:\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
}

int main() {
    int nBarang = 0;
    int nUser = 0;
    boolean isMasuk = false; // variabel untuk mengecek apakah user sudah login atau belum
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();


    system("cls || clear");
    displayWelcome();
    displatWelcomeMenu();

    printf("Silahkan pilih menu: ");
    STARTWORD();
    Word choice = CurrentWord;


    if (isKataSama(choice, "START")) {
        printf(">> START\n");
        start("../save/config.txt", &barang, &user, &nBarang, &nUser);
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

        struct timespec req = {2, 0};
        nanosleep(&req, NULL);
        system("cls || clear");
    }
    else if (isKataSama(choice, "LOAD")) {
        printf(">> LOAD\n");
        loadcheck(&barang, &user, &nBarang, &nUser);
    }
    else if (isKataSama(choice, "QUIT")) {
        printf(">> QUIT\n");
        quit(barang, user, nBarang, nUser);
    }
    else if (isKataSama(choice, "HELP")) {
        printf("QUIT\n");
    }
    else {
        printf("Invalid choice. Please try again.\n");
    }
    

    return 0;
}

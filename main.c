
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
#include "src/load.h"
#include "src/save.h"
#include "src/quit.h"

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

void displayMenu() {
    printf("\n\033[1;33mWelcome to PURRMART!\033[0m\n");
    printf("Please choose an option:\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
}

int main() {
    int nBarang = 0;
    int nUser = 0;
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();

    system("cls || clear");
    displayWelcome();
    displayMenu();

    printf("Enter your choice (1-3): ");
    STARTWORD();
    printf("%s\n", CurrentWord.TabWord);

    if(CurrentWord.TabWord == "START") {
        start(&barang, &user, &nBarang, &nUser);
    } else if(CurrentWord.TabWord == "LOAD") {
        loadcheck(&barang, &user, &nBarang, &nUser);
    } else if(CurrentWord.TabWord == "QUIT") {
        printf("Terima Kasih telah menggunakan PURRMART!\n");
        return 0;
    }
    

    return 0;
}

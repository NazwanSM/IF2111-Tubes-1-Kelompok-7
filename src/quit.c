#include "quit.h"

void quit() {
    printf("Apakah anda ingin save terlebih dahulu(y/n)?\n\n");
    START();
    while (GetCC() != 'Y' && GetCC() != 'y' && GetCC() != 'N' && GetCC() != 'n') {
        printf("Apakah anda ingin save terlebih dahulu(y/n)?\n");
    }
    if (GetCC() == 'Y' || GetCC() == 'y') {
        /*save*/
        printf("Save berhasil!\n");
    }
    else if (GetCC() == 'N' || GetCC() == 'n') {
        printf("Save dibatalkan!\n");
    }
    printf("Byee!\n");
    exit(0);
}
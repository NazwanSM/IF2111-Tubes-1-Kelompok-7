#include <stdio.h>
#include <stdlib.h>
#include "readtxt.h"



void manualStrcpy(char *dest, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0'; 
}

void readtxt(char *filename, Barang **barang, User **user, int nbarang, int nuser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", filename);
        return;
    }
    STARTWORDFILE(file);
    nbarang = atoi(CurrentWord.TabWord);
    *barang = (Barang *)malloc(nbarang * sizeof(Barang)); // Allocate memory for barang

    for (int i = 0; i < nbarang; i++) {
        ADVWORD(); 
        (*barang)[i].price = atoi(CurrentWord.TabWord);

        ADVWORDSpasi();
        manualStrcpy((*barang)[i].name, CurrentWord.TabWord);
    }

    if (!feof(file)) {
        ADVWORD();
    }

    nuser = atoi(CurrentWord.TabWord);
    *user = (User *)malloc(nuser * sizeof(User)); // Allocate memory for user

    for (int i = 0; i < nuser; i++) {
        ADVWORD();
        (*user)[i].money = atoi(CurrentWord.TabWord);

        ADVWORD();
        manualStrcpy((*user)[i].name, CurrentWord.TabWord);

        if (i == nuser - 1) {
            CopyWordFile();
        }
        else {
            ADVWORD();
        }
        manualStrcpy((*user)[i].password, CurrentWord.TabWord);
    }   
    fclose(file);
}


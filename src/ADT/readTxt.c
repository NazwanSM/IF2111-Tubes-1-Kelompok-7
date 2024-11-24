#include <stdio.h>
#include <stdlib.h>
#include "readTxt.h"
#include "arraydin.h"
#include "list.h"

void manualStrcpy(char *dest, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0'; 
}

void readtxt(char *filename, ArrayDin *barang, List *user, int *nbarang, int *nuser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Save file: %s tidak ditemukan. PURRMART gagal dijalankan.\n", filename);
        return;
    }
    STARTWORDFILE(file);
    *nbarang = atoi(CurrentWord.TabWord);
    (*barang).Neff = *nbarang;

    for (int i = 0; i < *nbarang; i++) {
        ADVWORDFILE(); 
        (*barang).A[i].price = atoi(CurrentWord.TabWord);

        ADVWORDSpasi();
        manualStrcpy((*barang).A[i].name, CurrentWord.TabWord);
        
    }

    if (!feof(file)) {
        ADVWORDFILE();
    }

    *nuser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < *nuser; i++) {
        ADVWORDFILE();
        (*user).A[i].money = atoi(CurrentWord.TabWord);

        ADVWORDFILE();
        manualStrcpy((*user).A[i].name, CurrentWord.TabWord);

        if (i == *nuser - 1) {
            CopyWordFile();
        }
        else {
            ADVWORDFILE();
        }
        manualStrcpy((*user).A[i].password, CurrentWord.TabWord);
    }   
    fclose(file);
}
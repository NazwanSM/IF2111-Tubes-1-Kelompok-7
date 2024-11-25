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

void readtxt(char *filename, ArrayDin *barang, List *user, int *nBarang, int *nUser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", filename);
        return;
    }
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan\n");
    STARTWORDFILE(file);
    *nBarang = atoi(CurrentWord.TabWord);
    (*barang).Neff = *nBarang;

    for (int i = 0; i < *nBarang; i++) {
        ADVWORDFILE(); 
        (*barang).A[i].price = atoi(CurrentWord.TabWord);

        ADVWORDSpasi();
        manualStrcpy((*barang).A[i].name, CurrentWord.TabWord);
    }

    if (!feof(file)) {
        ADVWORDFILE();
    }

    
    *nUser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < *nUser; i++) {
        ADVWORDFILE();
        (*user).A[i].money = atoi(CurrentWord.TabWord);

        ADVWORDFILE();
        manualStrcpy((*user).A[i].name, CurrentWord.TabWord);

        if (i == *nUser - 1) {
            CopyWordFile();
        }
        else {
            ADVWORDFILE();
        }
        manualStrcpy((*user).A[i].password, CurrentWord.TabWord);
    }   
    fclose(file);
}
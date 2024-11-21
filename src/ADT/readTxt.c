#include <stdio.h>
#include <stdlib.h>
#include "readtxt.h"
/* The `#include "arraydin.h"` and `#include "list.h"` lines are including header files named
`arraydin.h` and `list.h` respectively in the C program. */
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

void readtxt(char *filename, ArrayDin *barang, List *user, int nbarang, int nuser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", filename);
        return;
    }
    STARTWORD(file);
    nbarang = atoi(CurrentWord.TabWord);

    for (int i = 0; i < nbarang; i++) {
        ADVWORD(); 
        (*barang).A[i].price = atoi(CurrentWord.TabWord);

        ADVWORDSpasi();
        manualStrcpy((*barang).A[i].name, CurrentWord.TabWord);
    }

    if (!feof(file)) {
        ADVWORD();
    }

    nuser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < nuser; i++) {
        ADVWORD();
        (*user).A[i].money = atoi(CurrentWord.TabWord);

        ADVWORD();
        manualStrcpy((*user).A[i].name, CurrentWord.TabWord);

        if (i == nuser - 1) {
            CopyWord();
        }
        else {
            ADVWORD();
        }
        manualStrcpy((*user).A[i].password, CurrentWord.TabWord);
    }   
    fclose(file);
}


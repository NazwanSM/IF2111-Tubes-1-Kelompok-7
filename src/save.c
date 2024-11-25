#include <stdio.h>
#include <stdlib.h>

#include "save.h"

// Function to write data to a file
void write(char *filename, ArrayDin barang, List user, int nbarang, int nuser) {

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }
    
    fprintf(file, "%d\n", nbarang);
    for (int i = 0; i < nbarang; i++) {
        fprintf(file, "%d %s\n", barang.A[i].price, barang.A[i].name);
    }
    
    fprintf(file, "%d\n", nuser);
    for (int i = 0; i < nuser; i++) {
        fprintf(file, "%d %s %s\n", user.A[i].money, user.A[i].name, user.A[i].password);
    }    
    fclose(file);
}

void save(ArrayDin barang, List user, int nbarang, int nuser) {
    boolean check = false;
    do {
        printf("\n\033[1;34m>> SAVE\033[0m ");
        START();
        char savefile[100] = "save/";
        int savefileLen = 5;
        
        while (currentChar != '\n' && savefileLen < 100 - 1) {
            savefile[savefileLen++] = currentChar;
            READADV();
        }
        savefile[savefileLen] = '\0';

        boolean txt = false;
        int config = myStrcmp(savefile, "save/config.txt");

        if (savefile[savefileLen-4] == '.' && savefile[savefileLen-3] == 't' && savefile[savefileLen-2] == 'x' && savefile[savefileLen-1] == 't') {
            txt = true;
        }

        if (!config) {
            printf("Ini merupakan file konfigurasi, mohon jangan save disini!\n");
        } else if(!txt) {
            printf("\nPastikan file disimpan dalam format <nama file>.txt!\n");
        } else {
            printf("Save file berhasil disimpan\n");
            write(savefile, barang, user, nbarang, nuser);
            check = true;
        }
    } while (check == false);
}

/* int main() {

    ini semua deklarasi buat ngetes aja 

    ArrayDin barang = MakeArrayDin(); 
    List user = MakeList();
    barang.A[0].price = 10;
    manualStrcpy(barang.A[0].name, "AK47");
    barang.A[1].price = 20;
    manualStrcpy(barang.A[1].name, "Lalabu");
    user.A[0].money = 100;
    manualStrcpy(user.A[0].name, "admin");
    manualStrcpy(user.A[0].password, "alstrukdatkeren");
    user.A[1].money = 25;
    manualStrcpy(user.A[1].name, "prak");
    manualStrcpy(user.A[1].password, "kerenbangetkak");
    user.A[2].money = 325;
    manualStrcpy(user.A[2].name, "????");
    manualStrcpy(user.A[2].password, "inipasswordnya:*!@*!@&!*@&");
    int nbarang = 2;
    int nuser = 3;

    save(barang, user, nbarang, nuser);
    return 0;
} */

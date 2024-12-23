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
        int nRiwayat = Top(user.A[i].riwayat_pembelian) + 1;
        fprintf(file, "%d\n", nRiwayat);
        Stack writeStack;
        CreateEmptyStack(&writeStack);
        CopyStack(&(user.A[i].riwayat_pembelian), &writeStack);
        

        while (!IsEmptyStack(writeStack)) {
            infotypeStack X;
            Pop(&writeStack, &X);
            fprintf(file, "%d %d\n", X.items, X.biaya);
            for (int j = 0; j < X.items; j++) {
                fprintf(file, "%d %d %s\n", X.total[j], X.Value[j], X.Key[j].name);
            }
        }
        fprintf(file, "%d\n", NbElmt(user.A[i].wishlist));

        address P;
        boolean isFirst = true;
        if (!IsEmptyLink(user.A[i].wishlist))
        {
            P = First(user.A[i].wishlist);
            while (P != Nil)
            {
                if (!isFirst)
                {
                    fprintf(file, "\n");
                }
                fprintf(file, "%s", Info(P));
                isFirst = false;

                P = Next(P);
            }
        }
        if (i < nuser - 1 && !IsEmptyLink(user.A[i].wishlist)) {
            fprintf(file, "\n");  // Add newline between users but not after the last user
        }
    }
    fprintf(file, "\n");
    fclose(file);
}

void save(char *savefile, int savefileLen, ArrayDin barang, List user, int nbarang, int nuser) {
    boolean txt = false;
    int config = myStrcmp(savefile, "save/config.txt");

    if (savefile[savefileLen-4] == '.' && savefile[savefileLen-3] == 't' && savefile[savefileLen-2] == 'x' && savefile[savefileLen-1] == 't') {
        txt = true;
    }

    if (!config) {
        printf(COLOR_BOLD_RED"\nIni merupakan file konfigurasi, mohon jangan save disini!\n"COLOR_OFF);
    } else if(!txt) {
        printf(COLOR_BOLD_RED"\nPastikan file disimpan dalam format <nama file>.txt!\n"COLOR_OFF);
    } else {
        printf(COLOR_BOLD"Save file berhasil disimpan\n"COLOR_OFF);
        write(savefile, barang, user, nbarang, nuser);
    }

}

void savequit(ArrayDin barang, List user, int nbarang, int nuser) {
    boolean check = false;
    do {
        printf(COLOR_BOLD_CYAN"\n>> SAVE\033[0m\n\n");
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
            printf(COLOR_BOLD_RED"\nPastikan file disimpan dalam format <nama file>.txt!\n"COLOR_OFF);
        } else {
            printf(COLOR_BOLD"Save file berhasil disimpan\n"COLOR_OFF);
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
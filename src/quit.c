#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quit.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void quit(ArrayDin Barang, List User, int nBarang, int nUser, boolean change) {    
    if (change) {
        char cc ='\0';
        while (cc != 'Y' && cc != 'y' && cc != 'N' && cc != 'n') {
            printf("Apakah anda ingin save terlebih dahulu(y/n)? ");

            START();            
            cc = GetCC();       

            if (cc != 'Y' && cc != 'y' && cc != 'N' && cc != 'n') {
                printf("Masukkan 'y' untuk ya atau 'n' untuk tidak.\n");
                while (cc != '\n' && cc != EOF) {
                    ADV();       
                    cc = GetCC(); 
                }
            }
        }

        clearInputBuffer();
        
        if (cc == 'Y' || cc == 'y') {
            savequit(Barang, User, nBarang, nUser);
        }
        else if (cc == 'N' || cc == 'n') {
            printf("Save dibatalkan!\n");
        }
    }
    printf(COLOR_BOLD_YELLOW"\n------ "COLOR_OFF COLOR_BOLD_CYAN"TERIMA KASIH SUDAH BERKUNJUNG DI PURRMART"COLOR_OFF COLOR_BOLD_YELLOW" ------"COLOR_OFF);
    
    struct timespec req = {2, 0};
    nanosleep(&req, NULL);

    exit(0);
}
/*
int main(){
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

    quit(barang, user, nbarang, nuser);
}
*/
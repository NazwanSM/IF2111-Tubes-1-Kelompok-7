#include <stdio.h>
#include <stdlib.h>
#include "history.h"


void displayHistory(List user, int userIdx, int N){
    Stack tempStack; 
    CreateEmptyStack(&tempStack);
    CopyStack(&user.A[userIdx].riwayat_pembelian, &tempStack);   

    if (Top(tempStack) == NilS){
        printf("\033[1;31mAnda belum memiliki riwayat transaksi.\033[0m\n");
    } else {
        printf("\033[1;34mRiwayat pembelian barang:\033[0m\n");
        for (int i = 0; i < N; i++){
            if (IsEmptyStack(tempStack)){
                break;
            }
            infotypeStack temp;
            Pop(&tempStack, &temp);
            printf("Pembelian "COLOR_BOLD_RED"%d"COLOR_OFF" - Total "COLOR_BOLD_RED"%d\n"COLOR_OFF, i+1, temp.biaya);
            printf("\033[1;34m%-10s %-20s %-10s\033[0m\n", "Kuantitas", "Nama", "Total");
            for (int j = 0; j < temp.items; j++) {
                printf(COLOR_BOLD_YELLOW"%-10d"COLOR_OFF" %-20s "COLOR_BOLD_YELLOW"%-10d\n"COLOR_OFF, temp.Value[j], temp.Key[j].name, temp.total[j]);
            }
            printf("\n");
        }
    }
}
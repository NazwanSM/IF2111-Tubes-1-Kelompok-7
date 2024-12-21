#include <stdio.h>
#include "profile.h"

void displayBarangDimiliki(Stack history) {
    Map itemCount;
    itemCount.Count = 0;

    Stack tempStack;
    CreateEmptyStack(&tempStack);
    CopyStack(&history, &tempStack);

    while (!IsEmptyStack(tempStack)) {
        infotypeStack X;
        Pop(&tempStack, &X);
        
        boolean found = false;
        int i;
        for (i = 0; i < itemCount.Count; i++) {
            if (manualStrCmp(itemCount.Elements[i].Key.name, X.Key[0].name) == 0) {
                itemCount.Elements[i].Value += X.items;
                found = true;
                break;
            }
        }
        
        if (!found) {
            itemCount.Elements[itemCount.Count].Key = X.Key[0];
            itemCount.Elements[itemCount.Count].Value = X.items;
            itemCount.Count++;
        }
    }

    printf(COLOR_BOLD_YELLOW"\nDaftar Barang yang Dimiliki:\n"COLOR_OFF);
    for (int i = 0; i < itemCount.Count; i++) {
        printf(COLOR_BOLD_YELLOW"-"COLOR_OFF COLOR_BOLD" %s"COLOR_OFF" : "COLOR_BOLD_RED"%d\n"COLOR_OFF, 
            itemCount.Elements[i].Key.name, 
            itemCount.Elements[i].Value);
    }
}

void profile(List user, int userIdx){
    printf(COLOR_BOLD_YELLOW"Username : "COLOR_OFF COLOR_BOLD_CYAN"%s\n", user.A[userIdx].name);
    printf(COLOR_BOLD_YELLOW"Money : "COLOR_OFF COLOR_BOLD_CYAN"%d\n\n", user.A[userIdx].money);

    printf(COLOR_BOLD_BLUE"Total Pengeluaran : "COLOR_OFF);
    int total = 0;
    Stack tempstack;
    CreateEmptyStack(&tempstack);
    CopyStack(&(user.A[userIdx].riwayat_pembelian), &tempstack);
    while (!IsEmptyStack(tempstack)){
        infotypeStack X;
        Pop(&tempstack, &X);
        total += X.biaya;
    }
    printf(COLOR_BOLD_RED"%d\n"COLOR_OFF, total);
    printf(COLOR_BOLD_BLUE"Total Pendapatan : "COLOR_OFF COLOR_BOLD_GREEN"%d\n"COLOR_OFF, user.A[userIdx].money + total);

    displayBarangDimiliki(user.A[userIdx].riwayat_pembelian);
}
#include <stdio.h>
#include "cartAdd.h"

void cartAdd(List *user, int userIdx, ArrayDin store){
    elType itemArrayDin;
    int qty;

    printf("Nama barang yang akan ditambahkan: "); // Buat Sementara
    START();
    char item[100] = {0};
    int itemLen = 0;    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    } 
    item[itemLen] = '\0';

    manualStrcpy(itemArrayDin.name, item);
    itemArrayDin.price = -1;

    printf("Kuantitas Barang: "); // Buat Sementara
    STARTWORD();
    qty = atoi(CurrentWord.TabWord);

    int idx = search(store, itemArrayDin);
    if (idx == -1) {
        printf("Barang tidak ada di toko!\n");
        return;
    }
    else {
        InsertSetMap(&((*user).A[userIdx].keranjang), store.A[idx], qty);
        printf("\nBerhasil menambahkan %d %s ke keranjang belanja!\n", qty, store.A[idx].name);
    }
}
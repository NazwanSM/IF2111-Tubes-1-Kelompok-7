#include <stdio.h>
#include "cartRemove.h"

void cartRemove(List *user, int userIdx){
    elType itemArrayDin;
    int qty;

    char item[100] = {0};
    int itemLen = 0;    
    printf("Nama barang yang akan dihapus: "); 
    START();
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    } 
    item[itemLen] = '\0';

    manualStrcpy(itemArrayDin.name, item);
    itemArrayDin.price = -1;

    printf("Kuantitas Barang yang ingin dihapus: ");
    STARTWORD();
    qty = atoi(CurrentWord.TabWord);

    if (qty <= 0) {
        printf("Kuantitas barang yang dihapus harus lebih dari 0!\n");
        return;
    }

    int currentQty = ValueOfSetMap((*user).A[userIdx].keranjang, itemArrayDin);
    if (currentQty == 0) {
        printf("Barang tidak ditemukan di keranjang!\n");
        return;
    }
    else if (currentQty < qty) {
        printf("Kuantitas barang yang ingin dihapus melebihi kuantitas barang di keranjang!\n");
        return;
    }
    else {
        InsertSetMap(&((*user).A[userIdx].keranjang), itemArrayDin, currentQty - qty);
        printf("\nBerhasil menghapus %d %s dari keranjang belanja!\n", qty, itemArrayDin.name);
    }
}


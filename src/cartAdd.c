#include <stdio.h>
#include "cartAdd.h"

void cartAdd(List *user, int userIdx, ArrayDin store, char *namaBarang, int jumlah) {
    elType itemArrayDin;

    manualStrcpy(itemArrayDin.name, namaBarang);
    itemArrayDin.price = -1;


    int idx = search(store, itemArrayDin);
    if (idx == -1) {
        printf("Barang tidak ada di toko!\n");
        return;
    }
    else if (idx != -1 && !IsMemberSetMap((*user).A[userIdx].keranjang, store.A[idx])) {
        InsertSetMap(&((*user).A[userIdx].keranjang), store.A[idx], jumlah);
        printf("\nBerhasil menambahkan %d %s ke keranjang belanja!\n", jumlah, store.A[idx].name);
    }
    else {
        int currentQty = ValueOfSetMap((*user).A[userIdx].keranjang, store.A[idx]);
        InsertSetMap(&((*user).A[userIdx].keranjang), store.A[idx], currentQty + jumlah);
        printf("\nBerhasil menambahkan %d %s ke keranjang belanja!\n", jumlah, store.A[idx].name);
    }
}
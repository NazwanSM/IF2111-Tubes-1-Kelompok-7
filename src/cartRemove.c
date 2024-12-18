#include <stdio.h>
#include "cartRemove.h"

void cartRemove(List *user, int userIdx, char* namaBarang, int jumlah) {
    elType itemArrayDin;

    manualStrcpy(itemArrayDin.name, namaBarang);
    itemArrayDin.price = -1;

    if (!IsMember((*user).A[userIdx].keranjang, itemArrayDin)) {
        printf("Barang tidak ditemukan di keranjang!\n");
        return;
    }

    int currentQty = Value((*user).A[userIdx].keranjang, itemArrayDin);
    if (jumlah <= 0) {
        printf("Kuantitas barang yang dihapus harus lebih dari 0!\n");
        return;
    }
    else if (currentQty < jumlah){
        printf("Kuantitas barang yang ingin dihapus melebihi kuantitas barang di keranjang!\n");
        return;
    }
    else if (currentQty > jumlah) {
        InsertMap(&((*user).A[userIdx].keranjang), itemArrayDin, currentQty - jumlah);
        printf("\nBerhasil menghapus %d %s dari keranjang belanja!\n", jumlah, itemArrayDin.name);
    }
    else {
        DeleteMap(&((*user).A[userIdx].keranjang), itemArrayDin);
        printf("\nBerhasil menghapus %d %s dari keranjang belanja!\n", jumlah, itemArrayDin.name);
    }
}


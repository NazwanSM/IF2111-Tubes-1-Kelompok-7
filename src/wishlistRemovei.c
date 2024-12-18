#include <stdio.h>
#include <stdlib.h>
#include "wishlistRemovei.h"

void wishlistRemovei(List *user, int userIdx, int i) {
    address P = First((*user).A[userIdx].wishlist);
    if (IsEmptyLink((*user).A[userIdx].wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    } else {
        int a = 1;
        while (a < i && P != Nil) {
            P = Next(P);
            a++;
        }
        if (P == Nil) {
            printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", i);
        } else {
            DelP(&((*user).A[userIdx].wishlist), Info(P));
            printf("Berhasil menghapus barang posisi ke-%d di wishlist!\n", i);
        }
    }
}
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
            printf(COLOR_BOLD"Penghapusan barang WISHLIST gagal dilakukan, Barang ke-"COLOR_OFF COLOR_BOLD_RED"%d"COLOR_OFF COLOR_BOLD" tidak ada di WISHLIST!\n"COLOR_OFF, i);
        } else {
            DelP(&((*user).A[userIdx].wishlist), Info(P));
            printf(COLOR_BOLD"Berhasil menghapus barang posisi ke-"COLOR_OFF COLOR_BOLD_RED"%d"COLOR_OFF COLOR_BOLD" di wishlist!\n"COLOR_OFF, i);
        }
    }
}
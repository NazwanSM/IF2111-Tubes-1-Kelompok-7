#include <stdio.h>
#include <stdlib.h>
#include "wishlistSwap.h"


void wishlistSwap(List *user, int userIdx, int i, int j) {
    address P = First((*user).A[userIdx].wishlist);
    address Q = First((*user).A[userIdx].wishlist);
    int temp;
    if (j < i) {
        temp = j;
        j = i;
        i = temp;
    }

    int a = 1;
    int b = 1;
    while (a < i && P != Nil) {
        P = Next(P);
        a++;
    }
    while (b < j && Q != Nil) {
        Q = Next(Q);
        b++;
    }

    if (P == Nil || Q == Nil) {
        if (P != Nil && Q == Nil) {
            printf(COLOR_BOLD_RED"Gagal menukar posisi %s!\n"COLOR_OFF, Info(P));
        } else {
            printf("Posisi yang dimasukkan tidak valid\n");
        }
    } else {
        address Pafter = Alokasi(Info(P));
        address Qafter = Alokasi(Info(Q));

        InsertAfter(&((*user).A[userIdx].wishlist), Pafter, Q);
        DelP(&((*user).A[userIdx].wishlist), Info(Q));
        InsertAfter(&((*user).A[userIdx].wishlist), Qafter, P);
        DelP(&((*user).A[userIdx].wishlist), Info(P));

        printf(COLOR_BOLD"Berhasil menukar posisi %s dengan %s pada wishlist!\n"COLOR_OFF, Info(Pafter), Info(Qafter));
    }
}
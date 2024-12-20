#include <stdio.h>
#include <stdlib.h>
#include "wishlistShow.h"

void wishlistShow(List user, int userIdx) {
    if (IsEmptyLink(user.A[userIdx].wishlist)) {
        printf("\nWishlist kamu kosong!\n");
    } else {
        printf("\033[1;34mBerikut adalah isi wishlist-mu: \033[0m\n");
        address P;
        int i = 1;
        P = First(user.A[userIdx].wishlist);
        while (P != Nil)
        {
            printf(COLOR_BOLD_YELLOW"%d"COLOR_OFF" %s\n", i,Info(P));
            P = Next(P);
            i++;
        }
    }
}
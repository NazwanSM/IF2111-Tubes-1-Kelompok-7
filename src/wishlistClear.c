#include <stdio.h>
#include <stdlib.h>
#include "wishlistClear.h"

void wishlistClear(List *user, int userIdx) {
    address P;
    while (!IsEmptyLink((*user).A[userIdx].wishlist))
    {
        DelFirst(&(*user).A[userIdx].wishlist, &P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

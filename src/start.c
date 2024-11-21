#include<stdio.h>
#include<stdlib.h>
#include "start.h"

void start(char *filename, Barang **barang, User **user, int nbarang, int nuser) {
    readtxt("../save/config.txt", barang, user, nbarang, nuser);
}   

int main() {
    Barang *barang;
    /* (10 AK47, 20 Lalabu, ...)*/
    User *user;
    /* (2334 nama password. 223 kaka paseoersd,)*/
    int nbarang;
    int nuser;

    start("../save/config.txt", &barang, &user, nbarang, nuser);
    printf("%d %s\n",barang[0].price, barang[0].name);
    printf("%d %s %s\n",user[0].money, user[0].name, user[0].password);
    printf("%d", user[0].money +34);
    return 0;
}
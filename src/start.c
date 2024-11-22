#include<stdio.h>
#include<stdlib.h>
#include "start.h"
#include "ADT/arraydin.h"
#include "ADT/list.h"

void start(char *filename, ArrayDin *barang, List *user, int *nbarang, int *nuser) {
    readtxt("../save/config.txt", barang, user, nbarang, nuser);
}   

int main(){
    ArrayDin barang;
    List user;
    int nbarang, nuser;
    start("../save/config.txt", &barang, &user, nbarang, nuser);
    printf("Barang: %s\n", barang.A[0].name);
    return 0;
}
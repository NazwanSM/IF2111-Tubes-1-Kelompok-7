#include<stdio.h>
#include<stdlib.h>
#include "save.h"
#include "ADT/arraydin.h"
#include "ADT/list.h"

void start(char *filename, ArrayDin *barang, List *user, int *nbarang, int *nuser) {
    readtxt("../save/config.txt", barang, user, nbarang, nuser);
}    

/*
int main(){
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    start("../save/config.txt", &barang, &user, &nbarang, &nuser);
    int i = 0;
    int j = 0;
    while(i<nbarang){
        printf("%d %s\n", barang.A[i].price, barang.A[i].name);
        i++;
    }
    while(j<nuser){
        printf("%d %s %s\n", user.A[j].money, user.A[j].name, user.A[j].password);
        j++;
    }
    return 0;
}
*/
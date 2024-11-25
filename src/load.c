#include<stdio.h>
#include<stdlib.h>

#include "load.h"

void load(ArrayDin *barang, List *user, int *nbarang, int *nuser) {
    printf("Load: ");
    START();
    char loadfile[100] = "save/";
    int loadfileLen = 5;
    while (currentChar != '\n' && loadfileLen < 100 - 1) {
        loadfile[loadfileLen++] = currentChar;
        READADV();
    }
    loadfile[loadfileLen] = '\0';    
    readtxt(loadfile, barang, user, nbarang, nuser);
}   

void loadcheck(ArrayDin *barang, List *user, int *nbarang, int *nuser) {
    do {
        load(barang, user, nbarang, nuser);
    } while (*nuser == 0);
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan\n");
}

/* int main() {

    deklarasi buat ngetes
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    Queue q;
    CreateQueue(&q);

    nanti ditaro di main
    loadcheck(&barang, &user, &nbarang, &nuser);

    cuma buat ngetes
    printf("%d %s\n",barang.A[5].price, barang.A[5].name);
    printf("%d %s %s\n",user.A[0].money, user.A[0].name, user.A[0].password);
    printf("%d %s %s\n",user.A[1].money, user.A[1].name, user.A[1].password);
    printf("%d %s %s\n",user.A[2].money, user.A[2].name, user.A[2].password);
    printf("%d %s %s\n",user.A[3].money, user.A[3].name, user.A[3].password);
    printf("%d %s %s\n",user.A[4].money, user.A[4].name, user.A[4].password);
    printf("%d\n", user.A[3].money +34);
    printf("%d %d\n", nbarang, nuser);

    enqueue(&q, barang.A[3]);
    enqueue(&q, barang.A[3]);
    enqueue(&q, barang.A[2]);
    enqueue(&q, barang.A[4]);
    enqueue(&q, barang.A[1]);
    enqueue(&q, barang.A[0]);
    enqueue(&q, barang.A[3]);
    displayQueue(q);
    return 0;
} */
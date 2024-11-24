#include <stdio.h>
#include <stdlib.h>


#include "start.h"
#include "storeRequest.h"

void storeRequest(ArrayDin *barang, Queue antrian, int *nbarang) {
    elType itemArrayDin;
    idxType i, x;
    CreateQueue(&antrian);

    printf("Nama barang yang diminta: ");
    START();
    char item[100] = {0};
    int itemLen = 0;    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    } 
    item[itemLen] = '\0';

    manualStrcpy(itemArrayDin.name, item);
    itemArrayDin.price = -1;

    i = search(*barang, itemArrayDin);
    x = searchQueue(antrian, itemArrayDin);
    if(i == -1) {
        if (x == -1){
            printf("Berhasil menambahkan barang ke antrean\n");
            enqueue(&antrian, itemArrayDin);
        } else {
            printf("Barang sudah ada di antrean\n");
        }
    } else {
        printf("Barang sudah ada di store\n");
    }
}


int main() {
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    start("../save/config.txt", &barang, &user, &nbarang, &nuser);

    Queue antrian;
    CreateQueue(&antrian);
    storeRequest(&barang, antrian, &nbarang);
    printf("\n");
    displayQueue(antrian);
   
    return 0;
}

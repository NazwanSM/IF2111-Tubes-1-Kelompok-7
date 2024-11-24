
#include <stdio.h>
#include <stdlib.h>

#include "storeRequest.h"

void storeRequest(ArrayDin *store, Queue *antrian) {
    ElTypeQ itemQueue;

    printf("Nama barang yang diminta: ");
    START();
    char item[100] = {0};
    int itemLen = 0;    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    } 
    item[itemLen] = '\0';

    manualStrcpy(itemQueue.name, item);
    itemQueue.price = -1;

    if(search(*store, itemQueue) == -1) {
        if (!searchQueue(*antrian, itemQueue)){
            printf("Berhasil menambahkan barang ke antrean\n");
            enqueue(antrian, itemQueue);
        } else {
            printf("Barang sudah ada di antrean\n");
        }
    } else {
        printf("Barang sudah ada di store\n");
    }
}


/* int main() {
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    Queue q;
    CreateQueue(&q);

    loadcheck(&barang, &user, &nbarang, &nuser);

    storeRequest(&barang, &q);
    storeRequest(&barang, &q);
    storeRequest(&barang, &q);
    storeRequest(&barang, &q);
    storeRequest(&barang, &q);

    displayQueue(q);
    return 0;
}  */

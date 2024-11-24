#include <stdio.h>
#include <stdlib.h>

#include "start.h"
#include "save.h"
#include "load.h"
#include "storeList.h"

void storesupply(ArrayDin *barang, Queue *antrian, int *nbarang){
    while (!(isEmptyQueue(*antrian))){
        elType pilihan, baranginput;
        ElTypeQ x;
        printf("Apakah kamu ingin menambahkan barang %s: ", antrian->buffer[0].name);

        START();
        char item[100] = {0};
        int itemLen = 0;    
        while (currentChar != '\n' && itemLen < 100 - 1) {
            item[itemLen++] = currentChar;
            READADV();
        } 
        item[itemLen] = '\0';

        manualStrcpy(pilihan.name, item);
        pilihan.price = -1;

        if (myStrcmp(pilihan.name, "terima") == 0){
            int price;
            idxType i = *nbarang;
            ElTypeQ input;
            printf("Masukkan harga barang: ");
            scanf("%d", &price);
            antrian->buffer[0].price = price;
            insertAt(barang, antrian->buffer[0], i);
            dequeue(antrian, &x);
        } else if (myStrcmp(pilihan.name, "tolak") == 0) {
            enqueue(antrian, antrian->buffer[0]);
            dequeue(antrian, &x);
            printf("Barang ditolak dan dimasukkan kembali ke antrian.\n");
        } else {
            printf("Input tidak dikenali");
        }

        
    }
}

int main(){
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    start("../save/config.txt", &barang, &user, &nbarang, &nuser);
    elType pilihan;
    Queue antrian;
    ElTypeQ val;
    manualStrcpy(val.name, "hehe");  // Manually copy "hehe" to val.name
    val.price = -1;  // Assuming price should also be initialized

    enqueue(&antrian, val);
    storeList(barang, nbarang);
    printf("\n");
    storesupply(&barang, &antrian, &nbarang);
    printf("\n");
    storeList(barang, nbarang);
    printf("\n");
    printf("%s", pilihan.name[0]);
}


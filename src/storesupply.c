#include <stdio.h>
#include <stdlib.h>

#include "storeSupply.h"

void storesupply(ArrayDin *store, Queue *antrian, int *nbarang){
    ElTypeQ itemQueue;
    elType pilihan, baranginput;
    ElTypeQ x;
    if (!isEmptyQueue(*antrian)){    
        printf("Apakah kamu ingin menambahkan barang %s: ", antrian->buffer[antrian->idxHead].name);

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

        if (myStrcmp(pilihan.name, "TERIMA") == 0 || myStrcmp(pilihan.name, "Terima") == 0){
            int price;
            idxType i = *nbarang;
            ElTypeQ input;
            printf("Masukkan harga barang: ");
            
            START();
            char harga[100] = {0};
            int hargaLen = 0;    
            while (currentChar != '\n' && hargaLen < 100 - 1) {
                harga[hargaLen++] = currentChar;
                READADV();
            } 
            harga[hargaLen] = '\0';

            int hargabarang = atoi(harga);
            manualStrcpy(input.name, antrian->buffer[antrian->idxHead].name);
            input.price = hargabarang;

            insertAt(store, input, i);
            (*nbarang)++;
            dequeue(antrian, &x);
        } else if (myStrcmp(pilihan.name, "TUNDA") == 0 || myStrcmp(pilihan.name, "Tunda") == 0) {
            enqueue(antrian, antrian->buffer[antrian->idxHead]);
            dequeue(antrian, &x);
            printf("Barang ditunda dan dimasukkan kembali ke antrian.\n");
        } else if (myStrcmp(pilihan.name, "TOLAK") == 0 || myStrcmp(pilihan.name, "Tolak") == 0) {
            dequeue(antrian, &x);
            printf("Barang ditolak\n");
        } else {
            printf("Input tidak dikenali\n");
        }
    } else {
        printf("Antrian kosong\n");
    }

}

/*
int main(){
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    start("../save/config.txt", &barang, &user, &nbarang, &nuser);
    elType pilihan;
    Queue antrian;
    CreateQueue(&antrian);
    ElTypeQ val;

    
    storeList(barang, nbarang);

    storeRequest(&barang, &antrian);
    storeRequest(&barang, &antrian);
    storeRequest(&barang, &antrian);

    displayQueue(antrian);
    printf("\n");
    storesupply(&barang, &antrian, &nbarang);
    displayQueue(antrian);
    printf("\n");
    storeList(barang, nbarang);

    storesupply(&barang, &antrian, &nbarang);
    displayQueue(antrian);
    printf("\n");
    storeList(barang, nbarang);

    storesupply(&barang, &antrian, &nbarang);
    displayQueue(antrian);
    printf("\n");
    storeList(barang, nbarang);

    displayQueue(antrian);
    printf("\n");
}
*/

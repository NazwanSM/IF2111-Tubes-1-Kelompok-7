#include <stdio.h>
#include <stdlib.h>

#include "start.h"
#include "save.h"
#include "load.h"
#include "storeList.h"
#include "storeRequest.h"

int stringToInt(const char *str) {
    int result = 0;
    int sign = 1; // Untuk menangani angka negatif (opsional)
    int i = 0;

    // Tangani tanda negatif jika ada
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Iterasi tiap karakter dan ubah menjadi integer
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            printf("Input bukan angka.\n");
            return -1; // Tanda error jika ada karakter non-angka
        }
        result = result * 10 + (str[i] - '0');
    }

    return sign * result;
}

void storesupply(ArrayDin *store, Queue *antrian, int *nbarang){
    ElTypeQ itemQueue;
    elType pilihan, baranginput;
    ElTypeQ x;
    while (!(isEmptyQueue(*antrian))){
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
            idxType i = *nbarang + 1;
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

            int hargabarang = stringToInt(harga);
            manualStrcpy(input.name, antrian->buffer[0].name);
            input.price = hargabarang;

            insertAt(store, input, i);
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
    CreateQueue(&antrian);
    ElTypeQ val;

    
    storeList(barang, nbarang);

    storeRequest(&barang, &antrian);

    displayQueue(antrian);
    printf("\n");
    storesupply(&barang, &antrian, &nbarang);
    printf("\n");
    storeList(barang, nbarang);

    displayQueue(antrian);
    printf("\n");
}


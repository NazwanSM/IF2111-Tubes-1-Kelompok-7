#include <stdio.h>
#include "storeRequest.h"

void storeRequest(Barang *list){
    printf("Nama barang yang diminta: ");
    //Mendapatkan nama barang
    STARTWORD();

    char barang[MAX_LEN] = {0};
    int barangLen = 0;

    //Membaca nama barang
    while (CurrentWord != MARK && barangLen < MAX_LEN - 1) {
        barang[barangLen++] = CurrentWord;
        ADV();
    }

}
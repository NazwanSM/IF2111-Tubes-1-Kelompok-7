#include "cartShow.h"

void cartShow(List user, int userIdx){
    int total;
    int biaya = 0;
    
    if (user.A[userIdx].keranjang.Count == 0){
        printf("\nKeranjang kamu kosong!\n");
        return;
    }
    else{
        printf("Berikut adalah isi keranjangmu.\n");
        printf("\033[1;34m%-10s %-20s %-10s\033[0m\n", "Kuantitas", "Nama", "Total");
        for (int i = 0; i < user.A[userIdx].keranjang.Count; i++){
            total = user.A[userIdx].keranjang.Elements[i].Value * user.A[userIdx].keranjang.Elements[i].Key.price;
            printf("%-10d %-20s %-10d\n", user.A[userIdx].keranjang.Elements[i].Value, user.A[userIdx].keranjang.Elements[i].Key.name, total);
            biaya += total;
        }
        printf("\nTotal biaya yang harus dikeluarkan adalah "COLOR_BOLD_RED"%d\n"COLOR_OFF, biaya);
    }
}
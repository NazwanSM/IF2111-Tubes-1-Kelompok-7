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
        printf("\033[1;34mKuantitas\t\tNama\t\t\tTotal\033[0m\n");
        for (int i = 0; i < user.A[userIdx].keranjang.Count; i++){
            total = user.A[userIdx].keranjang.Elements[i].Value * user.A[userIdx].keranjang.Elements[i].Key.price;
            printf("%d\t\t\t%s\t\t\t%d\n", user.A[userIdx].keranjang.Elements[i].Value, user.A[userIdx].keranjang.Elements[i].Key.name, total);
            biaya += total;
        }
        printf("\nTotal biaya yang harus dikeluarkan adalah %d\n", biaya);
    }
}
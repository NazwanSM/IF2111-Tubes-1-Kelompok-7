#include "cartPay.h"

void cartPay(List user, int userIdx, boolean *change){
    int total;
    int biaya = 0;
    
    if (user.A[userIdx].keranjang.Count == 0){
        printf("\nKeranjang kamu kosong!\n");
        return;
    }
    else{
        printf("Kamu akan membeli barang-barang berikut.\n");
        printf("\033[1;34m%-10s %-20s %-10s\033[0m\n", "Kuantitas", "Nama", "Total");
        for (int i = 0; i < user.A[userIdx].keranjang.Count; i++){
            total = user.A[userIdx].keranjang.Elements[i].Value * user.A[userIdx].keranjang.Elements[i].Key.price;
            printf("%-10d %-20s %-10d\n", user.A[userIdx].keranjang.Elements[i].Value, user.A[userIdx].keranjang.Elements[i].Key.name, total);
            biaya += total;
        }
        printf("\nTotal biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli?", biaya);
        printf("\n(Ya/Tidak): ");
        STARTWORD();
        if (isKataSama(CurrentWord, "Ya")){
            if (user.A[userIdx].money < biaya){
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", user.A[userIdx].money);
                return;
            }
            else{
                for (int i = 0; i < user.A[userIdx].keranjang.Count; i++){
                    infotypeStack X;
                    X.biaya = biaya;
                    for (int i = 0; i < user.A[userIdx].keranjang.Count; i++){
                        manualStrcpy(X.Key[i].name, user.A[userIdx].keranjang.Elements[i].Key.name);
                        X.Key[i].price = user.A[userIdx].keranjang.Elements[i].Key.price;
                        X.Value[i] = user.A[userIdx].keranjang.Elements[i].Value;
                        X.total[i] = X.Value[i] * X.Key[i].price;
                        X.items++;
                    }
                    Push(&(user.A[userIdx].riwayat_pembelian), X);
                }
                user.A[userIdx].money -= biaya;
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
                CreateEmptyMap(&(user.A[userIdx].keranjang));
                *change = true;
                
            }
        }
        else{
            printf("Pembelian dibatalkan!\n");
        }
    }
}
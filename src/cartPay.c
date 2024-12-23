#include "cartPay.h"

void cartPay(List *user, int userIdx, boolean *change){
    int total;
    int biaya = 0;
    
    if (user->A[userIdx].keranjang.Count == 0){
        printf(COLOR_BOLD_RED"\nKeranjang kamu kosong!\n"COLOR_OFF);
        return;
    }
    else{
        printf("Kamu akan membeli barang-barang berikut.\n");
        printf("\033[1;34m%-10s %-20s %-10s\033[0m\n", "Kuantitas", "Nama", "Total");
        for (int i = 0; i < user->A[userIdx].keranjang.Count; i++){
            total = user->A[userIdx].keranjang.Elements[i].Value * user->A[userIdx].keranjang.Elements[i].Key.price;
            printf("%-10d %-20s %-10d\n", user->A[userIdx].keranjang.Elements[i].Value, user->A[userIdx].keranjang.Elements[i].Key.name, total);
            biaya += total;
        }
        printf("\nTotal biaya yang harus dikeluarkan adalah "COLOR_BOLD_RED"%d"COLOR_OFF", apakah jadi dibeli?", biaya);
        printf("\n(Ya/Tidak): ");
        STARTWORD();
        if (isKataSama(CurrentWord, "Ya")){
            if (user->A[userIdx].money < biaya){
                printf("Uang kamu hanya "COLOR_BOLD_RED"%d"COLOR_OFF", tidak cukup untuk membeli keranjang!\n", user->A[userIdx].money);
                return;
            }
            else{
                infotypeStack X;
                X.biaya = biaya;
                X.items = user->A[userIdx].keranjang.Count;
                
                X.Key = (keytype*)malloc(X.items * sizeof(keytype));
                X.Value = (valuetype*)malloc(X.items * sizeof(valuetype));
                X.total = (valuetype*)malloc(X.items * sizeof(valuetype));
                
                if (X.Key == NULL || X.Value == NULL || X.total == NULL) {
                    printf("Gagal mengalokasi memori!\n");
                    return;
                }
                
                for (int i = 0; i < user->A[userIdx].keranjang.Count; i++) {
                    manualStrcpy(X.Key[i].name, user->A[userIdx].keranjang.Elements[i].Key.name);
                    X.Key[i].price = user->A[userIdx].keranjang.Elements[i].Key.price;
                    X.Value[i] = user->A[userIdx].keranjang.Elements[i].Value;
                    X.total[i] = X.Value[i] * X.Key[i].price;
                }
                Push(&user->A[userIdx].riwayat_pembelian, X);

                user->A[userIdx].money -= biaya;
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");
                CreateEmptyMap(&(user->A[userIdx].keranjang));
                *change = true;
                
            }
        }
        else{
            printf(COLOR_BOLD_RED"Pembelian dibatalkan!\n"COLOR_OFF);
        }
    }
}
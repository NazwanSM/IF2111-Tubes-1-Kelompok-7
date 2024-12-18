#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wishlistAdd.h"



void wishlistAdd(List *user, ArrayDin *barang, int userIdx) {
    // Input barang yang ingin ditambahkan ke wishlist
    printf("Masukkan nama barang: ");
    STARTWORD();
    
    // Buat salinan nama barang untuk dimodifikasi
    char inputItemss[MAX_LEN];
    manualStrcpy(inputItemss, CurrentWord.TabWord);
    trimString(inputItemss);
    
    // Cek apakah barang sudah ada di wishlist
    address current = First((*user).A[userIdx].wishlist);
    while (current != Nil) {
        char wishlistItem[MAX_LEN];
        manualStrcpy(wishlistItem, Info(current));
        trimString(wishlistItem);
        
        if (strcmp(wishlistItem, inputItemss) == 0) {
            printf("%s sudah ada di wishlist!\n", inputItemss);
            return;
        }
        current = Next(current);
    }
    
    // Cek apakah barang tersedia di daftar barang (store)
    int barangFound = 0;
    for (int i = 0; i < (*barang).Neff; i++) {
        char storeItem[MAX_LEN];
        manualStrcpy(storeItem, (*barang).A[i].name);
        trimString(storeItem);
        
        if (strcmp(storeItem, inputItemss) == 0) {
            barangFound = 1;
            
            // Tambahkan ke wishlist
            InsVLast(&((*user).A[userIdx].wishlist), inputItemss);
            printf("Berhasil menambahkan %s ke wishlist!\n", inputItemss);
            return;
        }
    }
    
    // Jika barang tidak ditemukan di daftar barang
    if (!barangFound) {
        printf("Tidak ada barang dengan nama %s!\n", inputItemss);
    }
}


















































































































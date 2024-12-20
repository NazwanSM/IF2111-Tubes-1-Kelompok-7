#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wishlistRemove.h"


void wishlistRemove(List *user, int userIdx) {
    // Input barang yang ingin dihapus dari wishlist
    printf("Masukkan nama barang yang akan dihapus : ");
    STARTWORD();
    
    // Buat salinan nama barang untuk dimodifikasi
    char inputItemss[MAX_LEN];
    manualStrcpy(inputItemss, CurrentWord.TabWord);
    trimString(inputItemss);
    
    // Cari barang di wishlist
    address prev = Nil;
    address current = First((*user).A[userIdx].wishlist);
    int found = 0;
    
    while (current != Nil) {
        char wishlistItem[MAX_LEN];
        manualStrcpy(wishlistItem, Info(current));
        trimString(wishlistItem);
        
        if (strcmp(wishlistItem, inputItemss) == 0) {
            found = 1;
            
            // Hapus item dari wishlist
            if (prev == Nil) {
                // Hapus item pertama
                First((*user).A[userIdx].wishlist) = Next(current);
            } else {
                // Hapus item di tengah atau akhir
                Next(prev) = Next(current);
            }
            
            free(current);
            
            printf("%s berhasil dihapus dari WISHLIST!\n", inputItemss);
            return;
        }
        
        prev = current;
        current = Next(current);
    }
    
    // Jika barang tidak ditemukan di wishlist
    if (!found) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", inputItemss);
    }
}
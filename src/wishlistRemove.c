#include <stdio.h>
#include <stdlib.h>
#include "wishlistRemove.h"


void wishlistRemove(List *user, int userIdx) {
    printf("Masukkan nama barang yang akan dihapus : ");
    STARTWORD();
    Word choice = CurrentWord;

    while (currentChar != '\n') {
        ADVWORD();
        choice.TabWord[choice.Length] = ' ';
        choice.Length++;
        
        for (int i = 0; i < CurrentWord.Length; i++) {
            choice.TabWord[choice.Length] = CurrentWord.TabWord[i];
            choice.Length++;
        }
    }

    choice.TabWord[choice.Length] = '\0';

    char inputItemss[MAX_LEN];
    manualStrcpy(inputItemss, choice.TabWord);
    trimString(inputItemss);
    
    address prev = Nil;
    address current = First((*user).A[userIdx].wishlist);
    int found = 0;
    
    while (current != Nil) {
        char wishlistItem[MAX_LEN];
        manualStrcpy(wishlistItem, Info(current));
        trimString(wishlistItem);
        
        if (manualStrCmp(wishlistItem, inputItemss) == 0) {
            found = 1;
            
            if (prev == Nil) {
                First((*user).A[userIdx].wishlist) = Next(current);
            } else {
                Next(prev) = Next(current);
            }
            
            free(current);
            
            printf(COLOR_BOLD_BLUE"\n%s"COLOR_OFF" berhasil dihapus dari WISHLIST!\n", inputItemss);
            return;
        }
        
        prev = current;
        current = Next(current);
    }
    
    if (!found) {
        printf(COLOR_BOLD_RED"\nPenghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n"COLOR_OFF, inputItemss);
    }
}

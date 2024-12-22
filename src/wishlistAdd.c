#include <stdio.h>
#include <stdlib.h>
#include "wishlistAdd.h"



void wishlistAdd(List *user, ArrayDin *barang, int userIdx) {
    printf("Masukkan nama barang: ");
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
    
    address current = First((*user).A[userIdx].wishlist);
    while (current != Nil) {
        char wishlistItem[MAX_LEN];
        manualStrcpy(wishlistItem, Info(current));
        trimString(wishlistItem);
        
        if (manualStrCmp(wishlistItem, inputItemss) == 0) {
            printf(COLOR_BOLD_RED"\n%s sudah ada di wishlist!\n"COLOR_OFF, inputItemss);
            return;
        }
        current = Next(current);
    }
    
    int barangFound = 0;
    for (int i = 0; i < (*barang).Neff; i++) {
        char storeItem[MAX_LEN];
        manualStrcpy(storeItem, (*barang).A[i].name);
        trimString(storeItem);
        
        if (manualStrCmp(storeItem, inputItemss) == 0) {
            barangFound = 1;
            
            InsVLast(&((*user).A[userIdx].wishlist), inputItemss);
            printf("\nBerhasil menambahkan "COLOR_BOLD_BLUE"%s"COLOR_OFF" ke wishlist!\n", inputItemss);
            return;
        }
    }
    
    if (!barangFound) {
        printf(COLOR_BOLD_RED"\nTidak ada barang dengan nama %s!\n"COLOR_OFF, inputItemss);
    }
}

















































































































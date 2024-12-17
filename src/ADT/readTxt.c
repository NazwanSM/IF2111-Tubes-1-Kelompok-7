#include <stdio.h>
#include <stdlib.h>
#include "readTxt.h"


void readtxt(char *filename, ArrayDin *barang, List *user, int *nBarang, int *nUser) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", filename);
        return;
    }
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan\n");
    STARTWORDFILE(file);
    *nBarang = atoi(CurrentWord.TabWord);
    (*barang).Neff = *nBarang;

    for (int i = 0; i < *nBarang; i++) {
        ADVWORDFILE(); 
        (*barang).A[i].price = atoi(CurrentWord.TabWord);

        ADVWORDSpasi();
        manualStrcpy((*barang).A[i].name, CurrentWord.TabWord);
    }

    if (!feof(file)) {
        ADVWORDFILE();
    }

    
    *nUser = atoi(CurrentWord.TabWord);

    for (int i = 0; i < *nUser; i++) {
        CreateEmptyLink(&((*user).A[i].wishlist));
        CreateEmptyStack(&((*user).A[i].riwayat_pembelian));
        CreateEmptySetMap(&((*user).A[i].keranjang));
        
        Stack tempStack;
        CreateEmptyStack(&tempStack);
        ADVWORDFILE();
        (*user).A[i].money = atoi(CurrentWord.TabWord);

        ADVWORDFILE();
        manualStrcpy((*user).A[i].name, CurrentWord.TabWord);

        ADVWORDFILE();
        manualStrcpy((*user).A[i].password, CurrentWord.TabWord);

        ADVWORDFILE();
        int nRiwayat = atoi(CurrentWord.TabWord);

        for (int j = 0; j < nRiwayat; j++) {
            infotypeStack tempStackEl;
            ADVWORDFILE();
            int jumlahItem = atoi(CurrentWord.TabWord); 
            
            ADVWORDFILE();
            int totalTransaksi = atoi(CurrentWord.TabWord);

            tempStackEl.Key = (keytype*)malloc(jumlahItem * sizeof(keytype));
            tempStackEl.Value = (valuetype*)malloc(jumlahItem * sizeof(valuetype));
            tempStackEl.total = (valuetype*)malloc(jumlahItem * sizeof(valuetype)); 
            
            // Membaca setiap item dalam riwayat
            for (int k = 0; k < jumlahItem; k++) {
                ADVWORDFILE();
                tempStackEl.total[k] = atoi(CurrentWord.TabWord);  
                
                ADVWORDFILE();
                tempStackEl.Value[k] = atoi(CurrentWord.TabWord);  
                
                ADVWORDSpasi();
                manualStrcpy(tempStackEl.Key[k].name, CurrentWord.TabWord);   
                
            }
            tempStackEl.items = jumlahItem;     
            tempStackEl.biaya = totalTransaksi; 
                
            Push(&tempStack, tempStackEl);
        }

        while(!IsEmptyStack(tempStack)) {
            infotypeStack userStack;
            Pop(&tempStack, &userStack);
            Push(&((*user).A[i].riwayat_pembelian), userStack);
        }


        ADVWORDFILE();
        int nWishlist = atoi(CurrentWord.TabWord);
        for (int l = 0; l < nWishlist; l++) {
            if (i == *nUser - 1) {
                CopyWordSpasi();
            }
            else {
                ADVWORDSpasi();
            }
            InsVLast(&((*user).A[i].wishlist), CurrentWord.TabWord);
        }
    }   
    fclose(file);
}
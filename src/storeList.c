#include <stdio.h>
#include "storeList.h"

void storeList(ArrayDin barang, int nbarang){
    if (nbarang == 0){
        printf("TOKO KOSONG\n");
        return;
    }
    else {
        printf("\033[1;34mList barang yang ada di toko : \033[0m\n");
        for (int i = 0; i < nbarang; i++){
            printf(COLOR_BOLD_YELLOW"- "COLOR_OFF);
            printf("%s - ", barang.A[i].name);
            printf(COLOR_BOLD_BLUE"Harga: "COLOR_OFF COLOR_BOLD_RED"%d\n"COLOR_OFF, barang.A[i].price);
        }
    }
}

/*
int main(){
    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    start("../save/config.txt", &barang, &user, &nbarang, &nuser);

    storeList(barang, nbarang);

    return 0;
}
*/
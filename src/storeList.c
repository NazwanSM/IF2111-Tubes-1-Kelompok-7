#include <stdio.h>
#include "storeList.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/boolean.h"
#include "ADT/arraydin.h"
#include "ADT/readTxt.h"
#include "start.h"


void storeList(ArrayDin barang, int nbarang){
    printf("List barang yang ada di toko : \n");
    for (int i = 0; i < nbarang; i++){
        printf("- ");
        printf("%s\n", barang.A[i].name);
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
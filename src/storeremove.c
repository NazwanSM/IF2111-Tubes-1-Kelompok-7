#include <stdio.h>
#include <stdlib.h>

#include "storeremove.h"

void storeremove(ArrayDin *store, int *nbarang) {
    elType itemArrayDin;
    idxType i;

    printf("Nama barang yang akan dihapus: ");
    START();
    char item[100] = {0};
    int itemLen = 0;    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    } 
    item[itemLen] = '\0';

    manualStrcpy(itemArrayDin.name, item);
    itemArrayDin.price = -1;

    i = search(*store, itemArrayDin);
    if(i == -1) {
        printf("Toko tidak menjual barang %s\n", item);
    } else {
        deleteAt(store, i);
        (*nbarang)--;
        printf("%s telah berhasil dihapus\n", item);
    }
}


/* int main() {

    deklarasi buat ngetes

    ArrayDin barang = MakeArrayDin();
    List user = MakeList();
    int nbarang;
    int nuser;
    Queue q;
    CreateQueue(&q);
    User test;
    Barang tes;
    tes.price = 123;
    test.money = 6699;
    manualStrcpy(test.password, "kuburkankamuhiduphidup");

    ngetes

    loadcheck(&barang, &user, &nbarang, &nuser);
    printf("%s\n", barang.A[4].name);

    START();
    char item[100] = {0};
    int itemLen = 0;
    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        item[itemLen++] = currentChar;
        READADV();
    }
    item[itemLen] = '\0';
    manualStrcpy(test.name, item);

    START();
    char items[100] = {0};
    int itemsLen = 0;
    
    while (currentChar != '\n' && itemLen < 100 - 1) {
        items[itemsLen++] = currentChar;
        READADV();
    }
    items[itemsLen] = '\0';
    manualStrcpy(tes.name, items);

    if(Search(user, test)) {
        printf("ADA\n");
    }
    printf("%d/n", search(barang, tes));
    printf("%d %d/n", barang.Neff, barang.Capacity);
    storeremove(&barang, &nbarang);

    save(barang, user, nbarang, nuser);
    return 0;
} */
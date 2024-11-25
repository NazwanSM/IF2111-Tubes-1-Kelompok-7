#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main(){
    ArrayDin barang = MakeArrayDin();
    
    printf("Capacity: %d\n", getCapacity(barang));
    printf("Apakah kosong? %d\n");
    if (isEmpty(barang)) {
        printf("Array kosong\n");
    } else {
        printf("Array tidak kosong\n");
    }

    elType elem1 = {"Bola"};
    elType elem2 = {"AK47"};
    elType elem3 = {"Lalabu"};
    elType elem4 = {"Gitar"};

    // Melakukan insert element
    insertAt(&barang, elem1, 0);
    insertAt(&barang, elem2, 1);
    insertAt(&barang, elem3, 2);
    insertAt(&barang, elem4, 3);

    // Mencetak jumlah elemen efektif
    printf("Length: %d\n", length(barang));

    // Mencetak elemen array
    for (int i = 0; i < length(barang); i++) {
        printf("%s\n", get(barang, i).name);
    }

    // Mencetak elemen ke-3
    printf("Elemen ke-3: %s\n", get(barang, 2).name);

    // Menghapus elemen ke-3
    deleteAt(&barang, 2);

    // Mencetak jumlah elemen efektif
    printf("Length: %d\n", length(barang));

    // Mencetak elemen array
    for (int i = 0; i < length(barang); i++) {
        printf("%s\n", get(barang, i).name);
    }
    
    idxType idx = search(barang, elem1);
    if (idx != -1) {
        printf("Elemen '%s' ditemukan pada indeks: %d\n", elem1.name, idx);
    } else {
        printf("Elemen '%s' tidak ditemukan.\n", elem1.name);
    }


    DeallocateArrayDin(&barang);
    printf("Memori array telah dibebaskan.\n");

    return 0;
}
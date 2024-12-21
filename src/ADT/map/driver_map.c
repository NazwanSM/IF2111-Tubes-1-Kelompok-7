#include <stdio.h>
#include "map.h"

int main(){
    Map M;
    keytype k1, k2, k3;
    valuetype a = 1, b = 2, c = 3;

    // Membuat Map Kosong
    CreateEmptyMap(&M);
    if (IsEmptyMap(M)){
        printf("Map Kosong\n");
    }

    // Memasukkan nilai ke dalam map
    InsertMap(&M, k1, a);
    InsertMap(&M, k2, b);
    InsertMap(&M, k3, c);

    if (!IsEmptyMap(M)){
        printf("Map Tidak Kosong\n");
    }

    // Mencetak value dari keytype k1
    printf("%d\n", Value(M, k1));

    // Memeriksa apakah k2 merupakan bagian dari k2
    if (IsMember(M, k2)){
        printf("Dua merupakan anggota dari map\n");
    }

    // Menghapus seluruh nilai dalam map
    DeleteMap(&M, k1);
    DeleteMap(&M, k2);
    DeleteMap(&M, k3);

    // Memeriksa apakah map kosong
    if (IsEmptyMap(M)){
        printf("Map Kosong\n");
    }

    return 0;
}
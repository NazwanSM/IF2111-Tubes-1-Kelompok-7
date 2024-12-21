#include <stdio.h>
#include "listlinier.h"

int main() {
    LinkedList L;
    infotype X;
    address P, Prec;

    // Membuat list kosong
    CreateEmptyLink(&L);
    printf("List kosong: ");
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menambahkan elemen di awal
    InsVFirst(&L, "A");
    InsVFirst(&L, "B");
    InsVFirst(&L, "C");
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menambahkan elemen di akhir
    InsVLast(&L, "D");
    InsVLast(&L, "E");
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen pertama
    DelVFirst(&L, &X);
    printf("Hapus elemen pertama: %s\n", X);
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen terakhir
    DelVLast(&L, &X);
    printf("Hapus elemen terakhir: %s\n", X);
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menambahkan elemen dengan InsertFirst dan InsertLast
    P = Alokasi("F");
    InsertFirstLink(&L, P);
    P = Alokasi("G");
    InsertLastLink(&L, P);
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Mencari elemen
    P = SearchLink(L, "B");
    if (P != Nil) {
        printf("Elemen ditemukan: %s\n", Info(P));
    } else {
        printf("Elemen tidak ditemukan.\n");
    }
    printf("\n");

    // Menyisipkan elemen setelah elemen tertentu
    Prec = SearchLink(L, "G");
    if (Prec != Nil) {
        P = Alokasi("H");
        InsertAfter(P, Prec);
    }
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen pertama dengan DelFirst
    DelFirst(&L, &P);
    printf("Hapus elemen pertama: %s\n", Info(P));
    Dealokasi(&P);
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen tertentu
    DelP(&L, "G");
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen terakhir dengan DelLast
    DelLast(&L, &P);
    printf("Hapus elemen terakhir: %s\n", Info(P));
    Dealokasi(&P);
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Menghapus elemen setelah elemen tertentu
    Prec = SearchLink(L, "F");
    if (Prec != Nil) {
        DelAfter(&P, Prec);
        printf("Hapus elemen setelah: %s\n", Info(P));
        Dealokasi(&P);
    }
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    // Mengosongkan list
    while (!IsEmptyLink(L)) {
        DelVFirst(&L, &X);
        printf("Hapus elemen: %s\n", X);
    }
    PrintInfo(L);
    printf("\nJumlah elemen: %d\n\n", NbElmt(L));

    return 0;
}

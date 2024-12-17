#include <stdio.h>
#include "queue.h"
#include "mesinkata.h"

int main() {
    Queue queueBarang;
    CreateQueue(&queueBarang);

    // Membuat beberapa barang untuk diuji
    ElTypeQ barang1, barang2, barang3;
    
    // Barang 1: AK47
    barang1.price = 1000;
    strcpy(barang1.name, "AK47");

    // Barang 2: Lalabu
    barang2.price = 500;
    strcpy(barang2.name, "Lalabu");

    // Barang 3: Ayam Goreng Crisbar
    barang3.price = 250;
    strcpy(barang3.name, "Ayam Goreng Crisbar");

    // Menguji fungsi enqueue
    printf("Menambahkan barang ke dalam antrian:\n");
    enqueue(&queueBarang, barang1);
    enqueue(&queueBarang, barang2);
    enqueue(&queueBarang, barang3);

    // Menampilkan isi antrian
    printf("Isi antrian barang:\n");
    displayQueue(queueBarang);

    // Menguji fungsi dequeue
    ElTypeQ barangKeluar;
    dequeue(&queueBarang, &barangKeluar);
    printf("\nBarang yang dikeluarkan dari antrian: %s (Harga: %d)\n", barangKeluar.name, barangKeluar.price);

    // Menampilkan isi antrian setelah dequeue
    printf("\nIsi antrian barang setelah dequeue:\n");
    displayQueue(queueBarang);

    // Menguji fungsi isEmptyQueue dan isFullQueue
    printf("\nApakah antrian kosong? %s\n", isEmptyQueue(queueBarang) ? "Ya" : "Tidak");
    printf("Apakah antrian penuh? %s\n", isFullQueue(queueBarang) ? "Ya" : "Tidak");

    // Menguji fungsi lengthQueue
    printf("\nJumlah barang dalam antrian: %d\n", lengthQueue(queueBarang));

    // Menguji fungsi searchQueue
    ElTypeQ barangCari;
    strcpy(barangCari.name, "Lalabu");
    printf("\nApakah Lalabu ada dalam antrian? %s\n", searchQueue(queueBarang, barangCari) ? "Ya" : "Tidak");

    return 0;
}

/* File: work.h */

#ifndef WORK_H
#define WORK_H

#include "src/ADT/list.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/custom.h"
#include "src/ADT/boolean.h"

#define JUMLAH_PEKERJAAN 5

typedef struct {
    char* nama;
    int pendapatan;
    int durasi;
} Work;

typedef struct {
    Work A[JUMLAH_PEKERJAAN];
} WorkList;

extern WorkList daftarPekerjaan;

// Deklarasi fungsi
void isiDaftarPekerjaan(WorkList* daftarPekerjaan);
/* Mengisi list DaftarPekerjaan dengan struct pekerjaan */

void displayDaftarPekerjaan(WorkList *L);
/* Menampilkan daftar pekerjaan yang tersedia */

Work* cariPekerjaan(WorkList *L, Word input);
/* Fungsi untuk mencari pekerjaan yang diinputkan oleh user */

void prosesKerja(Work* work, List* user, int indexUser);
/* Fungsi untuk memproses pekerjaan yang dipilih oleh user */

void work(List* user, int indexUser);
/* Fungsi untuk menampilkan daftar pekerjaan yang tersedia dan meminta user untuk memilih pekerjaan yang ingin dikerjakan */

#endif
/* File: work.h */

#ifndef WORK_H
#define WORK_H

#include "src/ADT/list.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/custom.h"
#include "boolean.h"

#define JUMLAH_PEKERJAAN 5

typedef struct {
    char* nama;
    int pendapatan;
    int durasi;
} Work;

typedef struct {
    Work A[JUMLAH_PEKERJAAN];
} List;

// Deklarasi fungsi
void isiDaftarPekerjaan(List* daftarPekerjaan);
/* Mengisi list DaftarPekerjaan dengan struct pekerjaan */

void displayDaftarPekerjaan(List *L);
/* Menampilkan daftar pekerjaan yang tersedia */

boolean isKataSama(Word kata1, char* kata2);
/* Fungsi untuk membandingkan kata */

Work* cariPekerjaan(List *L, Word input);
/* Fungsi untuk mencari pekerjaan yang diinputkan oleh user */

void prosesKerja(Work* work, User* user);
/* Fungsi untuk memproses pekerjaan yang dipilih oleh user */

void work(User* user);
/* Fungsi untuk menampilkan daftar pekerjaan yang tersedia dan meminta user untuk memilih pekerjaan yang ingin dikerjakan */

#endif
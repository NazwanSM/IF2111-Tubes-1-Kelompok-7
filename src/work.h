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
void displayDaftarPekerjaan(List *L);
boolean isKataSama(Word kata1, char* kata2);
Work* findPekerjaanByWord(List *L, Word input);
void prosesKerja(Work* work, User* user);
void work(User* user);


#endif

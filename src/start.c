#include<stdio.h>
#include<stdlib.h>
#include "start.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/list//list.h"

void start(char *filename, ArrayDin *barang, List *user, int *nBarang, int *nUser) {
    readtxt("save/config.txt", barang, user, nBarang, nUser);
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
} 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "work.h"

WorkList daftarPekerjaan;

void isiDaftarPekerjaan(WorkList* daftarPekerjaan){
    
    Work pekerjaan[JUMLAH_PEKERJAAN] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };
    
    for(int i = 0; i < JUMLAH_PEKERJAAN; i++) {
        daftarPekerjaan->A[i] = pekerjaan[i];
    }
}

void displayDaftarPekerjaan(WorkList *L){
    printf("Daftar pekerjaan:\n");
    for(int i = 0; i < JUMLAH_PEKERJAAN; i++) {
        printf("%d. %s (pendapatan = %d, durasi = %ds)\n", i + 1, L->A[i].nama, L->A[i].pendapatan, L->A[i].durasi);
    }
}

boolean isKataSama(Word kata1, char* kata2){

    int panjangKata2 = 0;
    while (kata2[panjangKata2] != '\0') {
        panjangKata2++;
    }

    if (kata1.Length != panjangKata2) {
        return false;
    }
    
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2[i]) {
            return false;
        }
    }
    return true;
}

Work* cariPekerjaan(WorkList *L, Word input){
    for(int i = 0; i < JUMLAH_PEKERJAAN; i++){
        if(isKataSama(input, L->A[i].nama)){
            return &L->A[i];
        }
    }
    return NULL;
}

void prosesKerja(Work* work, List* user, int indexUser){
    printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", work->nama);
    
    struct timespec req = {work->durasi, 0};
    nanosleep(&req, NULL);
    
    user->A[indexUser].money += work->pendapatan;
    
    printf("\nPekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", 
        work->pendapatan);
}

void work(List* user, int indexUser){

    displayDaftarPekerjaan(&daftarPekerjaan);
    
    printf("\nMasukkan pekerjaan yang dipilih: ");
    
    STARTWORD();
    Word inputPekerjaan = CurrentWord;
    
    while (currentChar != '\n'){
        ADVWORD();
        inputPekerjaan.TabWord[inputPekerjaan.Length] = ' ';
        inputPekerjaan.Length++;
        
        for (int i = 0; i < CurrentWord.Length; i++){
            inputPekerjaan.TabWord[inputPekerjaan.Length] = CurrentWord.TabWord[i];
            inputPekerjaan.Length++;
        }
    }
    
    Work* selectedWork = cariPekerjaan(&daftarPekerjaan, inputPekerjaan);
    
    if (selectedWork == NULL){
        printf("Pekerjaan tidak ditemukan!\n");
        return;
    }
    
    prosesKerja(selectedWork, user, indexUser);
}
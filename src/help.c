#include "help.h"

void help1() {
    printf("=====[Welcome Menu Help PURRMART]=====\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("3. QUIT -> Untuk keluar dari program\n");
}

void help2() {
    printf("=====[Login Menu Help PURRMART]=====\n");
    printf("1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("3. QUIT -> Untuk keluar dari program\n");
}

void help3() {
    printf("=====[Main Menu Help PURRMART]=====\n");
    printf("1. WORK -> Untuk bekerja\n");
    printf("2. WORKCHALLENGE -> Untuk mengerjakan challenge\n");
    printf("3. STORELIST -> Untuk melihat barang-barang di toko\n");
    printf("4. STOREREQUEST -> Untuk meminta penambahan barang\n");
    printf("5. STORESUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("6. STOREREMOVE -> Untuk menghapus barang\n");
    printf("7. LOGOUT -> Untuk keluar dari sesi\n");
    printf("8. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("9. QUIT -> Untuk keluar dari program\n");
}

/*
int main(){
    help1();
    printf("\n");
    help2();
    printf("\n");
    help3();
    return 0;
}
*/
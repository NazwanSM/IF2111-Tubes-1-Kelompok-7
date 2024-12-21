#include "help.h"

void help1() {
    printf("\n\033[1;33m=====[Welcome Menu Help PURRMART]=====\033[0m\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("3. QUIT -> Untuk keluar dari program\n");
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF"START -> Untuk masuk sesi baru\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "QUIT -> Untuk keluar dari program\n");
}

void help2() {
    printf("\n\033[1;33m=====[Login Menu Help PURRMART]=====\033[0m\n");
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF "REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "QUIT -> Untuk keluar dari program\n");
}

void help3() {
    printf("\n\033[1;33m=====[Main Menu Help PURRMART]=====\033[0m\n");
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF "PROFILE -> Untuk mengecek profile\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "WORK -> Untuk bekerja\n");
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf(COLOR_BOLD_YELLOW"4.  "COLOR_OFF "STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf(COLOR_BOLD_YELLOW"5.  "COLOR_OFF "STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf(COLOR_BOLD_YELLOW"6.  "COLOR_OFF "STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf(COLOR_BOLD_YELLOW"7.  "COLOR_OFF "STORE REMOVE -> Untuk menghapus barang\n");
    printf(COLOR_BOLD_YELLOW"8.  "COLOR_OFF "CART ADD -> Untuk menambahkan barang ke keranjang\n");
    printf(COLOR_BOLD_YELLOW"9.  "COLOR_OFF "CART REMOVE -> Untuk menghapus barang dari keranjang\n");
    printf(COLOR_BOLD_YELLOW"10. "COLOR_OFF "CART SHOW -> Untuk melihat isi keranjang\n");
    printf(COLOR_BOLD_YELLOW"11. "COLOR_OFF "CART PAY -> Untuk membayar barang di keranjang\n");
    printf(COLOR_BOLD_YELLOW"12. "COLOR_OFF "HISTORY -> Untuk melihat riwayat transaksi\n");
    printf(COLOR_BOLD_YELLOW"13. "COLOR_OFF "WISHLIST ADD -> Untuk menambahkan barang ke wishlist\n");
    printf(COLOR_BOLD_YELLOW"14. "COLOR_OFF "WISHLIST SWAP -> Untuk menukar barang pada wishlist\n");
    printf(COLOR_BOLD_YELLOW"15. "COLOR_OFF "WISHLIST REMOVE -> Untuk menghapus barang pada wishlist\n");
    printf(COLOR_BOLD_YELLOW"16. "COLOR_OFF "WISHLIST REMOVE <nomor> -> Untuk menghapus barang pada wishlist\n");
    printf(COLOR_BOLD_YELLOW"17. "COLOR_OFF "WISHLIST CLEAR -> Untuk menghapus seluruh barang pada wishlist\n");
    printf(COLOR_BOLD_YELLOW"18. "COLOR_OFF "WISHLIST SHOW -> Untuk melihat isi wishlist\n");
    printf(COLOR_BOLD_YELLOW"19. "COLOR_OFF "OPTIMASI RUTE -> Untuk mengoptimalkan rute\n");
    printf(COLOR_BOLD_YELLOW"20. "COLOR_OFF "LOGOUT -> Untuk keluar dari sesi\n");
    printf(COLOR_BOLD_YELLOW"21. "COLOR_OFF "SAVE -> Untuk menyimpan state ke dalam file\n");
    printf(COLOR_BOLD_YELLOW"22. "COLOR_OFF "QUIT -> Untuk keluar dari program\n");
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
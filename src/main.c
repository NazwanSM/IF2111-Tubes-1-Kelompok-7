#include <stdio.h>
#include <stdlib.h>
#include "work.h"
#include "work_challenge.h"

  // Dummy user untuk testing
User createDummyUser() {
    User dummy;
    dummy.money = 10000;  // Initial money untuk testing
    return dummy;
}

  // Fungsi untuk menampilkan status user
void displayUserStatus(User* user) {
    printf("\n=== Status User ===\n");
    printf("Uang: %d rupiah\n", user->money);
    printf("================\n\n");
}

int main() {
    // Inisialisasi user
    User user = createDummyUser();
    
      // Inisialisasi daftar pekerjaan
    isiDaftarPekerjaan(&daftarPekerjaan);
    
    int pilihan;
    boolean selesai = false;
    
    while (!selesai) {
        printf("\nMenu Utama:\n");
        printf("1. Bekerja (WORK)\n");
        printf("2. Work Challenge\n");
        printf("3. Lihat Status User\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        
        STARTWORD();
        pilihan = atoi(CurrentWord.TabWord);
        
        switch(pilihan) {
            case 1:
                printf("\n=== Menu Bekerja ===\n");
                work(&user);
                break;
                
            case 2:
                printf("\n=== Menu Work Challenge ===\n");
                work_challenge(&user);
                break;
                
            case 3:
                displayUserStatus(&user);
                break;
                
            case 4:
                selesai = true;
                printf("Terima kasih telah bermain!\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    return 0;
}
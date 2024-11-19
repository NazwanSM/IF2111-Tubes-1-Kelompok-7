#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "work_challenge.h"

// Daftar kata valid untuk permainan
const char* validWords[] = {
    "KEREN", "SMART", "BRAIN", "THINK", "LOGIC",
    "STUDY", "BODOH", "WRITE", "SPEAK", "DREAM",
    "HAPPY", "SMILE", "LAUGH", "SEMUT", "QUIET",
    "QUICK", "KIMIA", "FLASH", "LIGHT", "ZOMBI"
};
const int numValidWords = 20;


int tebak_angka(User* user){
    // Mengecek uang user
    if (user->money < GAME_COST1){
        printf("Uang Anda tidak cukup untuk bermain game ini.\n");
        return -1;
    }

    // Mengurangi uang user
    updateUserMoney(user, -GAME_COST1);

    // Membuat angka random
    srand(time(NULL));
    int target = rand() % 100 + 1;
    int attempts = 0, guess, reward;

    // Menebak angka
    while (attempts < MAX_ATTEMPTS1){
        printf("Tebak angka: ");

        STARTWORD();
        guess = WordToInt(CurrentWord);

        attempts++;
        
        // Jika tebakan benar
        if (guess == target){
            reward = 500 - ((attempts -1) * 30);
            if (reward < 200) reward = 200;

                updateUserMoney(user, reward);
                printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda.\n", reward);
                return reward;
        }
        // Jika tebakan salah
        else if (guess < target){
            printf("Tebakanmu lebih kecil!\n");
        }
        else {
            printf("Tebakanmu lebih besar!\n");
        }
    }
    
    // Jika percobaan habis
    printf("Maaf, kamu kehabisan kesempatan. Angka yang benar adalah: %d\n", target);
    return 0;
}

boolean isValidWord(Word input){
    // Mengecek panjang kata
    if (input.Length != WORD_LENGTH){
        return false;
    }

     // Konversi input ke uppercase untuk perbandingan
    char upperInput[WORD_LENGTH + 1];
    int i;
    for (i = 0; i < input.Length; i++){
        if (input.TabWord[i] >= 'a' && input.TabWord[i] <= 'z') {
            upperInput[i] = input.TabWord[i] - 'a' + 'A';
        } 
        else {
            upperInput[i] = input.TabWord[i];
        }
    }
    upperInput[i] = '\0';
    
    // Cek apakah kata ada dalam daftar kata valid
    for (i = 0; i < numValidWords; i++){
        boolean match = true;
        for (int j = 0; j < WORD_LENGTH; j++){
            if (upperInput[j] != validWords[i][j]){
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

void displayGuessResult(char target[], char guess[], int length){
    // Array untuk menandai huruf yang sudah digunakan
    boolean used[WORD_LENGTH] = {false};
    
    // Pertama, cek huruf yang benar di posisi yang tepat
    for (int i = 0; i < length; i++){
        if (guess[i] == target[i]){
            printf("%c", guess[i]);
            used[i] = true;
        } 
        else {
            // Cek apakah huruf ada di posisi lain
            boolean found = false;
            for (int j = 0; j < length; j++){
                if (!used[j] && guess[i] == target[j]){
                    printf("%c*", guess[i]);
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%c%%", guess[i]);
            }
        }
    }
    printf("\n");
}

int WORLD3(User* user){
    // Mengecek uang user
    if (user->money < GAME_COST2) {
        printf("Uang Anda tidak cukup untuk bermain game ini.\n");
        return -1;
    }

    // Mengurangi uang user
    updateUserMoney(user, -GAME_COST2);

    // Pilih kata target secara random
    srand(time(NULL));
    const char* targetWord = validWords[rand() % numValidWords];

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n", MAX_ATTEMPTS2);

    for (int i = 0; i < MAX_ATTEMPTS2; i++){
        printf("_ _ _ _ _ \n");
    }

    int attempts = 0;
    boolean won = false;
    Word guess[MAX_ATTEMPTS2];

    // Menebak kata
    while (attempts < MAX_ATTEMPTS2 && !won){
        printf("\nMasukkan kata tebakan Anda: ");
        STARTWORD();

        // Mengecek validitas kata
        if (!isValidWord(CurrentWord)){
            printf("Kata tidak valid! Masukkan kata 5 huruf yang valid.\n");
            continue;
        }

        // Menyimpan kata tebakan
        guess[attempts] = CurrentWord;

        printf("Hasil: \n");

        for (int j = 0; j <= attempts; j++){
            displayGuessResult(targetWord, guess[j].TabWord, WORD_LENGTH);
        }

        for (int j = attempts + 1; j < MAX_ATTEMPTS2; j++){
            printf("_ _ _ _ _\n");
        }

        boolean correct = true;
        for (int k = 0; k < WORD_LENGTH; k++){
            if (targetWord[k] != guess[attempts].TabWord[k]){
                correct = false;
                break;
            }
        }

        if (correct) {
            printf("\nSelamat, Anda menang!\n");
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", WORLD3_REWARD);
            updateUserMoney(user, WORLD3_REWARD);
            return WORLD3_REWARD;
        }

        attempts++;
    }

    printf("\nBoo! Anda kalah.\n");
    printf("Kata yang benar adalah: %s\n", targetWord);
    return 0;
}

void work_challenge(User* user){
    printf("Selamat datang di Work Challenge!\n");
    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (Biaya: %d rupiah)\n", GAME_COST1);
    printf("2. WORDL399 (Biaya: %d rupiah)\n", GAME_COST2);

    int challenge;
    printf("Masukkan challenge yang hendak dimainkan: ");
    STARTWORD();
    challenge = WordToInt(CurrentWord);

    if (challenge == 1){
        return tebak_angka(user);
    }
    else if (challenge == 2){
        return WORLD3(user);
    }
    else {
        printf("Challenge tidak valid!\n");
    }
}
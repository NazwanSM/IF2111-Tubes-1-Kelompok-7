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

int tebak_angka(List* user, int userIdx){
    // Mengecek uang user
    if (user->A[userIdx].money < GAME_COST1){
        printf(COLOR_BOLD_RED"Uang Anda tidak cukup untuk bermain game ini.\n"COLOR_OFF);
        return -1;
    }

    // Mengurangi uang user
    user->A[userIdx].money -= GAME_COST1;

    // Membuat angka random
    srand(time(NULL));
    int target = rand() % 100 + 1;
    int attempts = 0, guess, reward;

    // Menebak angka
    while (attempts < MAX_ATTEMPTS1){
        printf("Tebak angka: ");

        STARTWORD();
        guess = atoi(CurrentWord.TabWord);

        attempts++;
        
        // Jika tebakan benar
        if (guess == target){
            reward = 500 - ((attempts -1) * 30);
            if (reward < 200) reward = 200;

                user->A[userIdx].money += reward;
                printf("Tebakanmu benar! "COLOR_BOLD_RED"+%d"COLOR_OFF" rupiah telah ditambahkan ke akun anda.\n", reward);
                return reward;
        }
        // Jika tebakan salah
        else if (guess < target){
            printf("Tebakanmu lebih kecil!\n\n");
        }
        else {
            printf("Tebakanmu lebih besar!\n\n");
        }
    }
    
    // Jika percobaan habis
    printf("Maaf, kamu kehabisan kesempatan. Angka yang benar adalah: %d\n", target);
    return 0;
}

boolean isValidWord(Word input){
    // Hanya mengecek panjang kata (harus 5 huruf)
    if (input.Length != WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < input.Length; i++) {
        if (input.TabWord[i] >= 'a' && input.TabWord[i] <= 'z') {
            input.TabWord[i] = input.TabWord[i] - 32; // Konversi ke uppercase
        }
    }
}

void displayGuessResult(const char target[], const char guess[], int length){
    // Array untuk menandai huruf yang sudah digunakan
    boolean used[WORD_LENGTH] = {false};
    
    // Pertama, cek huruf yang benar di posisi yang tepat
    for (int i = 0; i < length; i++){
        if (guess[i] == target[i]){
            printf("%c  ", guess[i]);
            used[i] = true;
        } 
        else {
            // Cek apakah huruf ada di posisi lain
            boolean found = false;
            for (int j = 0; j < length; j++){
                if (!used[j] && guess[i] == target[j]){
                    printf("%c* ", guess[i]);
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%c%% ", guess[i]);
            }
        }
    }
    printf("\n");
}

int W0RDL3(List* user, int userIdx){
    // Mengecek uang user
    if (user->A[userIdx].money < GAME_COST2) {
        printf("Uang Anda tidak cukup untuk bermain game ini.\n");
        return -1;
    }

    // Mengurangi uang user
    user->A[userIdx].money -= GAME_COST2;

    // Pilih kata target secara random
    srand(time(NULL));
    const char* targetWord = validWords[rand() % numValidWords];

    printf("\n\033[1;33mWELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\033[0m\n\n", MAX_ATTEMPTS2);

    for (int i = 0; i < MAX_ATTEMPTS2; i++){
        printf("_ _ _ _ _ \n");
    }

    int attempts = 0;
    boolean won = false;
    Word guess[MAX_ATTEMPTS2];

    // Menebak kata
    while (attempts < MAX_ATTEMPTS2 && !won){
        printf("\n(Kata bisa dalam bahasa Inggris / Indonesia dan harus kapital)\n");
        printf("Masukkan kata tebakan Anda: ");
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
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", W0RDL3_REWARD);
            user->A[userIdx].money += W0RDL3_REWARD;
            return W0RDL3_REWARD;
        }

        attempts++;
    }

    printf("\nBoo! Anda kalah.\n");
    printf("Kata yang benar adalah: %s\n", targetWord);
    return 0;
}

void work_challenge(List* user, int userIdx){
    printf("\033[1;33mSelamat datang di Work Challenge!\033[0m\n\n");
    printf("\033[1;34mDaftar challenge yang tersedia:\033[0m\n");
    printf("1. Tebak Angka (Biaya: %d rupiah)\n", GAME_COST1);
    printf("2. W0RDL3 (Biaya: %d rupiah)\n", GAME_COST2);

    printf("\nMasukkan challenge yang hendak dimainkan: ");
    STARTWORD();
    Word challenge = CurrentWord;

    while (currentChar != '\n'){
            ADVWORD();
            challenge.TabWord[challenge.Length] = ' ';
            challenge.Length++;
        
                for (int i = 0; i < CurrentWord.Length; i++){
                    challenge.TabWord[challenge.Length] = CurrentWord.TabWord[i];
                    challenge.Length++;
                }
            }

    if (isKataSama(challenge, "Tebak Angka") || isKataSama(challenge, "tebak angka") || isKataSama(challenge, "TEBAK ANGKA")){
        tebak_angka(user, userIdx);
    }
    else if (isKataSama(challenge, "W0RDL3") || isKataSama(challenge, "w0rdl3") || isKataSama(challenge, "W0rdl3")){
        W0RDL3(user, userIdx);
    }
    else {
        printf("Challenge tidak valid!\n");
    }
}
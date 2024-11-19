/* File: work_challenge.h */

#ifndef WORK_CHALLENGE_H
#define WORK_CHALLENGE_H

#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/custom.h"
#include "boolean.h"

#define GAME_COST1 200
#define GAME_COST2 500
#define MAX_ATTEMPTS1 10
#define MAX_ATTEMPTS2 5
#define WORD_LENGTH 5
#define WORLD3_REWARD 1500


int tebak_angka(User* user);
/* Permainan tebak angka yang akan meminta user untuk menebak angka dengan maksimal 10 percobaan
Jika percobaan habis akan return 0
Jika uang lebih kecil dari 200 maka akan return -1
Jika benar maka akan mengupdate uang dari user */

int WORLD3(User* user);
/* Permainan world 3 yang akan meminta user untuk menebak kata berjumlah 5 karakter dengan maksimal 5 percobaan 
Jika percobaan habis akan return 0
Jika uang lebih kecil dari 500 maka akan return -1
Jika benar maka akan mengupdate uang dari user */ 

void displayGuessResult(char target[], char guess[], int length);
/* Fungsi untuk menampilkan hasil tebakan user */

boolean isValidWord(Word input);
/* Fungsi untuk memeriksa apakah kata yang dimasukkan memenuhi syarat atau tidak */

void work_challenge(User* user);
/* Fungsi untuk menampilkan daftar challenge yang tersedia dan meminta user untuk memilih challenge yang ingin dimainkan */

#endif
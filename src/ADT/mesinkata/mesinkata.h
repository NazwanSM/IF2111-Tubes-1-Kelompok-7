/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean/boolean.h"
#include "../mesinkarakter/mesinkarakter.h"
#include <stdio.h>

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CurrentWord;

void manualStrcpy(char *dest, const char *source);

int manualStrCmp(char* str1, char* str2);

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreBlanksFile();

void STARTWORD();
/* I.S. : currentChar sembarang
F.S. : EndWord = true, dan currentChar = MARK;
      atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(FILE *inputFile);

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
      currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
      Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVWORDSpasi();

void ADVWORDFILE();

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
I.S. : currentChar adalah karakter pertama dari kata
F.S. : currentWord berisi kata yang sudah diakuisisi;
      currentChar = BLANK atau currentChar = MARK;
      currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordFile();

void CopyWordSpasi();

boolean isKataSama(Word kata1, char* kata2);
/* Fungsi untuk membandingkan kata */

#endif
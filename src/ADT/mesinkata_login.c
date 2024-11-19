#include <stdio.h>
#include "mesinkata_login.h"
#include "boolean.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : karSekarang sembarang
   F.S. : karSekarang ≠ BLANK atau karSekarang = MARK */
    while ((currentChar == BLANK) && (currentChar != MARK)){
        ADV();
    }
}

void STARTWORD(){
/* I.S. : karSekarang sembarang
   F.S. : EndWord = true, dan karSekarang = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          karSekarang karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
/* I.S. : karSekarang adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          karSekarang adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika karSekarang = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : karSekarang adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          karSekarang = BLANK atau karSekarang = MARK;
          karSekarang adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int idx = 0;
    while (currentChar != MARK && currentChar != BLANK && idx < NMax) {
        CurrentWord.TabWord[idx] = currentChar;
        ADV();
        idx++;
    }
    CurrentWord.Length = idx;
}

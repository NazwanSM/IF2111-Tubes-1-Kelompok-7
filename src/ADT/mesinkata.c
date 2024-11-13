#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    
    EndWord = (currentChar == MARK);
    ADVWORD();
}
/* I.S. : currentChar sembarang
F.S. : EndWord = true, dan currentChar = MARK;
        atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();

    EndWord = (currentChar == MARK);
    CopyWord();
    IgnoreBlanks();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i=0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (i<NMax)){
        CurrentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    CurrentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
I.S. : currentChar adalah karakter pertama dari kata
F.S. : currentWord berisi kata yang sudah diakuisisi;
        currentChar = BLANK atau currentChar = MARK;
        currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
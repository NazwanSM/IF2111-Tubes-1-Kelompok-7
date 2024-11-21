#include <stdio.h>
#include "mesinkata_readtxt.h"
#include "mesinkarakter_readtxt.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
    while ((currentChar == BLANK || currentChar == '\n') && currentChar != MARK) {
        ADV();
    }
}

/* Mengabaikan satu atau beberapa BLANK
I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(FILE *inputFile){
    START(inputFile);
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

void ADVWORDSpasi(){
    IgnoreBlanks();

    EndWord = (currentChar == MARK);
    CopyWordSpasi();
    IgnoreBlanks();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord() {
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != '\n') && (i < NMax)) {
        CurrentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    CurrentWord.TabWord[i] = '\0';
    CurrentWord.Length = i;
}

/* Mengakuisisi kata, menyimpan dalam currentWord
I.S. : currentChar adalah karakter pertama dari kata
F.S. : currentWord berisi kata yang sudah diakuisisi;
        currentChar = BLANK atau currentChar = MARK;
        currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordSpasi() {
    int i = 0;
    while ((currentChar != MARK) && (currentChar != '\n') && (i < NMax)) {
        if (currentChar != BLANK || i != 0) { // Ignore leading spaces but keep spaces within names
            CurrentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    CurrentWord.TabWord[i] = '\0'; // Null-terminate the string
    CurrentWord.Length = i;
}



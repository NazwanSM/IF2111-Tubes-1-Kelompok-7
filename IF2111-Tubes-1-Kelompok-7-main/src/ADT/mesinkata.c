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

void IgnoreBlanksFile(){
    while ((currentChar == BLANK || currentChar == '\n') && currentChar != MARK){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    
    EndWord = (currentChar == MARK);
    ADVWORD();
}

void STARTWORDFILE(FILE *inputFile){
    STARTFILE(inputFile);
    IgnoreBlanksFile();
    
    EndWord = (currentChar == MARK);
    ADVWORDFILE();
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

void ADVWORDSpasi(){
    IgnoreBlanksFile();

    EndWord = (currentChar == MARK);
    CopyWordSpasi();
    IgnoreBlanksFile();
}

void ADVWORDFILE(){
    IgnoreBlanksFile();

    EndWord = (currentChar == MARK);
    CopyWordFile();
    IgnoreBlanksFile();
}

void CopyWord(){
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != '\n' && i < NMax) {
        CurrentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    CurrentWord.TabWord[i] = '\0'; 
    CurrentWord.Length = i;
}

void CopyWordFile(){
    int i=0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (currentChar!='\n') && (i<NMax)){
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

void CopyWordSpasi(){
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

boolean isKataSama(Word kata1, char* kata2){

    int panjangKata2 = 0;
    while (kata2[panjangKata2] != '\0') {
        panjangKata2++;
    }

    if (kata1.Length != panjangKata2) {
        return false;
    }
    
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2[i]) {
            return false;
        }
    }
    return true;
}
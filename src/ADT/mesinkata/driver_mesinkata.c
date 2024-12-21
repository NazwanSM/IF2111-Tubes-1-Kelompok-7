#include <stdio.h>
#include "mesinkata.h"

int main() {
    printf("=== Driver ADT Mesin Kata ===\n\n");

    // Test STARTWORD dan ADVWORD
    printf("Masukkan beberapa kata (akhiri dengan titik): ");
    STARTWORD();
    
    printf("\nKata-kata yang dimasukkan:\n");
    while (!EndWord) {
        for (int i = 0; i < CurrentWord.Length; i++) {
            printf("%c", CurrentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }

    // Test isKataSama
    printf("\nTest isKataSama:\n");
    Word testWord;
    testWord.Length = 7;
    char testString[] = "PURRMART";
    for (int i = 0; i < testWord.Length; i++) {
        testWord.TabWord[i] = testString[i];
    }
    testWord.TabWord[testWord.Length] = '\0';

    printf("Apakah kata 'PURRMART' sama dengan 'PURRMART'? %s\n", 
        isKataSama(testWord, "PURRMART") ? "Ya" : "Tidak");
    printf("Apakah kata 'PURRMART' sama dengan 'PURRMALL'? %s\n", 
        isKataSama(testWord, "PURRMALL") ? "Ya" : "Tidak");

    // Test STARTWORDFILE
    printf("\nTest membaca dari file:\n");
    FILE *testFile = fopen("bin/test_input.txt", "r");
    if (testFile == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return 1;
    }

    STARTWORDFILE(testFile);
    printf("Kata-kata dari file:\n");
    while (!EndWord) {
        for (int i = 0; i < CurrentWord.Length; i++) {
            printf("%c", CurrentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORDFILE();
    }
    fclose(testFile);

    return 0;
}

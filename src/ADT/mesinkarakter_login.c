#include <stdio.h>
#include "mesinkarakter_login.h"

char currentChar;
boolean EOP;
static FILE *pita;

void START() {
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Algoritma */
    fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}
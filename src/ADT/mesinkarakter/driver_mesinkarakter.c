#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    START();
    while (!EOP) {
        printf("%c", GetCC());
        ADV();
    }
}
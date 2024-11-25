#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void displayWelcome() {
    printf("\033[1;33m"); 
    printf(" ######  ##  ## ######  ######  ##   ##  ######  ######  ######\n");
    printf(" ##  ##  ##  ## ##  #   ##  #   ### ###  ##  ##  ##  #     ##  \n");
    printf(" ######  ##  ## ######  ######  ## # ##  ######  ######    ##  \n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf(" ##      ##  ## ##  ##  ##  ##  ##   ##  ##  ##  ##  ##    ##  \n");
    printf(" ##       ####  ##  ##  ##  ##  ##   ##  ##  ##  ##  ##    ##  \n");
    printf("\033[0m");
}
void displayWelcomeMenu() {
    printf("\n\033[1;33mWELCOME TO PURRMART!\033[0m\n\n");
    printf("\033[1;34mPILIHAN MENU:\033[0m\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. QUIT\n");
    printf("\n\033[1;34mKetik 'HELP' untuk bantuan\033[0m\n");
}

int main() {
    displayWelcome();

    struct timespec req = {2, 0};
    nanosleep(&req, NULL);
    displayWelcomeMenu();
    return 0;
}
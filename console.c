#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

void displayPurrMart() {
    printf(COLOR_BOLD_YELLOW" ######  ##  ## ######  ######"COLOR_OFF COLOR_BOLD_CYAN"  ##   ##  ######  ######  ######\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW" ##  ##  ##  ## ##  #   ##  # "COLOR_OFF COLOR_BOLD_CYAN"  ### ###  ##  ##  ##  #     ##  \n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW" ######  ##  ## ######  ######"COLOR_OFF COLOR_BOLD_CYAN"  ## # ##  ######  ######    ##  \n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW" ##      ##  ## ##  ##  ##  ##"COLOR_OFF COLOR_BOLD_CYAN"  ##   ##  ##  ##  ##  ##    ##  \n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW" ##       ####  ##  ##  ##  ##"COLOR_OFF COLOR_BOLD_CYAN"  ##   ##  ##  ##  ##  ##    ##  \n"COLOR_OFF);
}

void displayWelcomeMenu() {
    printf(COLOR_BOLD_CYAN_BLINK"\nWELCOME TO PURRMART!\n\n"COLOR_OFF);
    printf(COLOR_BOLD_BLUE"PILIHAN MENU:\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF"START\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "LOAD" COLOR_CYAN" <nama_file>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "QUIT\n");
    printf(COLOR_BOLD_BLUE"\nKetik "COLOR_OFF COLOR_BOLD_RED"HELP"COLOR_OFF COLOR_BOLD_BLUE" untuk bantuan\n"COLOR_OFF);
}

void displayLoginMenu() {
    printf(COLOR_BOLD_CYAN_BLINK"\nLOGIN OR SIGNUP TO YOUR ACCOUNT!\n\n"COLOR_OFF);
    printf(COLOR_BOLD_BLUE"PILIHAN MENU:\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF "REGISTER\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "LOGIN\n");
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "QUIT\n");
    printf(COLOR_BOLD_BLUE"\nKetik "COLOR_OFF COLOR_BOLD_RED"HELP"COLOR_OFF COLOR_BOLD_BLUE" untuk bantuan\n"COLOR_OFF);
}

void displayMainMenu() {
    printf(COLOR_BOLD_CYAN_BLINK"\nWELCOME TO MAIN MENU\n\n"COLOR_OFF);
    printf(COLOR_BOLD_BLUE "PILIHAN MENU:\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"1.  "COLOR_OFF "PROFILE\n");
    printf(COLOR_BOLD_YELLOW"2.  "COLOR_OFF "WORK\n");
    printf(COLOR_BOLD_YELLOW"3.  "COLOR_OFF "WORK CHALLENGE\n");
    printf(COLOR_BOLD_YELLOW"4.  "COLOR_OFF "STORE LIST\n");
    printf(COLOR_BOLD_YELLOW"5.  "COLOR_OFF "STORE REQUEST\n");
    printf(COLOR_BOLD_YELLOW"6.  "COLOR_OFF "STORE SUPPLY\n");
    printf(COLOR_BOLD_YELLOW"7.  "COLOR_OFF "STORE REMOVE\n");
    printf(COLOR_BOLD_YELLOW"8.  "COLOR_OFF "CART ADD "COLOR_CYAN"<nama> <jumlah>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"9.  "COLOR_OFF "CART REMOVE "COLOR_CYAN"<nama> <jumlah>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"10. "COLOR_OFF "CART SHOW\n");
    printf(COLOR_BOLD_YELLOW"11. "COLOR_OFF "CART PAY\n");
    printf(COLOR_BOLD_YELLOW"12. "COLOR_OFF "HISTORY " COLOR_CYAN"<jumlah>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"13. "COLOR_OFF "WISHLIST ADD\n");
    printf(COLOR_BOLD_YELLOW"14. "COLOR_OFF "WISHLIST SWAP "COLOR_CYAN"<nomor1> <nomor2>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"15. "COLOR_OFF "WISHLIST REMOVE "COLOR_CYAN"<nomor>\n"COLOR_OFF);
    printf(COLOR_BOLD_YELLOW"16. "COLOR_OFF "WISHLIST CLEAR\n");
    printf(COLOR_BOLD_YELLOW"17. "COLOR_OFF "WISHLIST SHOW\n");
    printf(COLOR_BOLD_YELLOW"18. "COLOR_OFF "LOGOUT\n");
    printf(COLOR_BOLD_YELLOW"19. "COLOR_OFF "SAVE\n");
    printf(COLOR_BOLD_YELLOW"20. "COLOR_OFF "QUIT\n");
    printf(COLOR_BOLD_BLUE"\nKetik "COLOR_OFF COLOR_BOLD_RED"HELP"COLOR_OFF COLOR_BOLD_BLUE" untuk bantuan\n"COLOR_OFF);
}
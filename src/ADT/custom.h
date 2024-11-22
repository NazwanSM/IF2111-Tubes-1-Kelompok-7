/* File: custom.h */

#ifndef CUSTOM_H
#define CUSTOM_H

#define MAX_LEN 100
//#define Mark '\0' /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

#define integer int


typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    integer money;
} User;

typedef struct {
    char name[MAX_LEN];
    integer price;
} Barang;


// Fungsi untuk mengupdate uang user
void updateUserMoney(User *user, int amount);

#endif
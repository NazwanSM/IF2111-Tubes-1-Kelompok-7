/* File: custom.h */

#ifndef CUSTOM_H
#define CUSTOM_H

#define MAX_LEN 100

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
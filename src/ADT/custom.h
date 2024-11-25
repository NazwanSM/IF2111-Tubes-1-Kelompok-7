/* File: custom.h */

#ifndef CUSTOM_H
#define CUSTOM_H

#include "boolean.h"

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

#endif
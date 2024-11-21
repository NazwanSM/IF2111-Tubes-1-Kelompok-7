#include<stdio.h>
#include<stdlib.h>
#include "start.h"

void start(char *filename, Barang **barang, User **user, int nbarang, int nuser) {
    readtxt("../save/config.txt", barang, user, nbarang, nuser);
}   

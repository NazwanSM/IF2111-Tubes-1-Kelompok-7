#include<stdio.h>
#include<stdlib.h>
#include "start.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/list//list.h"

void start(ArrayDin *barang, List *user, int *nBarang, int *nUser) {
    readtxt("save/config.txt", barang, user, nBarang, nUser);
} 
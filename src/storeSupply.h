#ifndef STOREREMOVE_H
#define STOREREMOVE_H

#include "start.h"
#include "save.h"
#include "load.h"
#include "storeList.h"
#include "storeRequest.h"

void storesupply(ArrayDin *store, Queue *antrian, int *nbarang);
/* Fungsi membaca barang pada antrian lalu menentukan apakah barang akan dimasukkan ke store*/

#endif
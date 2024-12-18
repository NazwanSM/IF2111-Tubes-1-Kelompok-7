#ifndef __LOAD_H__
#define __LOAD_H__

#include "ADT/readTxt/readTxt.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/list/list.h"
#include "ADT/queue/queue.h"

void load(ArrayDin *barang, List *user, int *nbarang, int *nuser);
/* Fungsi untuk load file txt */

void loadcheck(ArrayDin *barang, List *user, int *nbarang, int *nuser);
/* pengecekan apakah file txt sudah ada
ges ini BELOM tentu dibutuhin yak ternyata di spesifikasi gaada ngecek input.. */

#endif
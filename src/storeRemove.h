#ifndef STOREREMOVE_H
#define STOREREMOVE_H

#include "load.h"
#include "save.h"
#include "ADT/arraydin.h"
#include "ADT/custom.h"
#include "ADT/list.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"
#include "ADT/boolean.h"


void storeremove(ArrayDin *store, int *nbarang);
/* Fungsi menghapus barang yang ada pada toko. 
   Menerima input nama barang dan mengembalikan ArrayDin berupa store dengan input
   nama barang yang sudah dihapus dan store.Neff - 1. Jika input tidak ada di toko,
   fungsi tidak melakukan apapun*/

#endif
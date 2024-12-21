#ifndef STORE_REMOVE_H
#define STORE_REMOVE_H

#include "load.h"
#include "save.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/custom/custom.h"
#include "ADT/list/list.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/boolean/boolean.h"


void storeremove(ArrayDin *store, int *nbarang);
/* Fungsi menghapus barang yang ada pada toko. 
   Menerima input nama barang dan mengembalikan ArrayDin berupa store dengan input
   nama barang yang sudah dihapus dan store.Neff - 1. Jika input tidak ada di toko,
   fungsi tidak melakukan apapun*/

#endif
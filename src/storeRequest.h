#ifndef STOREREQUEST_H
#define STOREREQUEST_H

#include "load.h"
#include "save.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/boolean.h"
#include "ADT/arraydin.h"
#include "ADT/readTxt.h"
#include "start.h"

void storeRequest(ArrayDin *store, Queue antrian, int *nbarang);
/* Fungsi menghapus barang yang ada pada toko. 
   Menerima input nama barang dan mengembalikan ArrayDin berupa store dengan input
   nama barang yang sudah dihapus dan store.Neff - 1. Jika input tidak ada di toko,
   fungsi tidak melakukan apapun*/

#endif
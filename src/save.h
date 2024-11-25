#ifndef __SAVE_H__
#define __SAVE_H__

#include "ADT/readTxt.h"
#include "ADT/arraydin.h"
#include "ADT/list.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"
#include "ADT/boolean.h"

void write(char *filename, ArrayDin barang, List user, int nbarang, int nuser);
/* Menyimpan file input dalam bentuk txt */

void save(ArrayDin barang, List user, int nbarang, int nuser);
/* Fungsi save yang menerima masukkan file input dan kemudian diperiksa.
File input dipastikan txt dengan format <namafile>.txt dan user tidak diperbolehkan
untuk save pada config.txt karena merupakan file konfigurasi */

#endif
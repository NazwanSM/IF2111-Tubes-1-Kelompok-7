#ifndef __SAVE_H__
#define __SAVE_H__

#include "ADT/readTxt/readTxt.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/list/list.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/boolean/boolean.h"

void write(char *filename, ArrayDin barang, List user, int nbarang, int nuser);
/* Menyimpan file input dalam bentuk txt */

void save(ArrayDin barang, List user, int nbarang, int nuser);
/* Fungsi save yang menerima masukkan file input dan kemudian diperiksa.
File input dipastikan txt dengan format <namafile>.txt dan user tidak diperbolehkan
untuk save pada config.txt karena merupakan file konfigurasi */

#endif
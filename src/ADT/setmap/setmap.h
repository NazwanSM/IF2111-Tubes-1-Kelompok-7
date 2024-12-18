/* File: setmap.h */
#ifndef SETMAP_H
#define SETMAP_H

#include <stdio.h>
#include <string.h>
#include "../boolean/boolean.h"
#include "../custom/custom.h"

/* KONSTRUKTOR */
void CreateEmptySetMap(SetMap *sm);
/* I.S. sembarang */
/* F.S. Membuat sebuah SetMap sm kosong dengan sm.Count = NilM */

/* PREDIKAT */
boolean IsSetMapEmpty(SetMap sm);
/* Mengembalikan true jika SetMap kosong: sm.Count = NilM */

boolean IsSetMapFull(SetMap sm);
/* Mengembalikan true jika SetMap penuh: sm.Count = MaxEl */

boolean IsMemberSetMap(SetMap sm, keytype k);
/* Mengembalikan true jika k adalah member dari SetMap sm */

/* PRIMITIF */
void InsertSetMap(SetMap *sm, keytype k, valuetype v);
/* I.S. sm mungkin kosong, mungkin penuh */
/* F.S. Menambahkan k dengan v ke sm jika k belum ada */
/*      Jika k sudah ada, update v */
/*      Jika sm penuh, tidak melakukan apa-apa */

void DeleteSetMap(SetMap *sm, keytype k);
/* I.S. sm tidak kosong */
/* F.S. Menghapus k dari sm jika ada */

valuetype ValueOfSetMap(SetMap sm, keytype k);
/* Mengembalikan value yang berpasangan dengan k di sm */
/* Mengembalikan Undefined jika k tidak ditemukan */

void PrintSetMap(SetMap sm);
/* I.S. sm terdefinisi */
/* F.S. Menampilkan isi sm ke layar */

#endif

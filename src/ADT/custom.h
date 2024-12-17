/* File: custom.h */

#ifndef CUSTOM_H
#define CUSTOM_H

#include "boolean.h"

#define COLOR_BOLD_CYAN_BLINK  "\e[1;5;36m"
#define COLOR_BOLD_BLUE_BLINK  "\e[1;5;34m"
#define COLOR_BOLD_BLUE   "\e[1;34m"
#define COLOR_BOLD_GREEN  "\e[1;32m"
#define COLOR_BOLD_RED    "\e[1;31m"
#define COLOR_BOLD_YELLOW "\e[1;33m"
#define COLOR_BOLD_CYAN   "\e[1;36m"
#define COLOR_BOLD       "\e[1m"
#define COLOR_CYAN       "\e[36m"
#define COLOR_OFF   "\e[0m"
#define COLOR_BLINK "\e[5m"

#define MAX_LEN 100
#define integer int
typedef struct {
    char name[MAX_LEN];
    integer price;
} Barang;

#define NilS -1
#define MaxEl 50

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define NilM 0
#define Undefined 0

// typedef int bool;
typedef Barang keytype;
typedef int valuetype;
typedef int addressMap;

typedef struct {
	keytype Key;
	valuetype Value;
} infotypeMap;

typedef struct {
	infotypeMap Elements[MaxEl];
	addressMap Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/*MODUL Stack*/

/* Nil adalah stack dengan elemen kosong . */
typedef int addressStack; /* indeks tabel */
typedef struct {
	valuetype biaya;
    valuetype items;
    keytype *Key;
	valuetype *Value;
    valuetype *total;
} infotypeStack;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotypeStack T[MaxEl]; /* tabel penyimpan elemen */
  addressStack TOP;       /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* MODUL LinkedList */
#define Nil NULL

typedef char infotype[50];
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype info;
    address next;
} ElmtList;
typedef struct
{
    address First;
} LinkedList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    integer money;
    Map keranjang;
    Stack riwayat_pembelian;
    LinkedList wishlist;
} User;

#endif
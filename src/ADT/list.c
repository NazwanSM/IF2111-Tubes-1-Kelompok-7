#include <stdio.h>
#include "list.h"
/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List L;
    int i;
    
    for (i = 0; i < MaxEl; i++) {
        L.A[i] = Mark;
    }
    
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return L.A[0] == Mark;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    L->A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    int i;
    int count = 0;
    for (i = 0; i < MaxEl; i++) {
        if (L.A[i] != Mark) {
            count++;
            }
    }
    
    return count;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    if (IsEmpty(L)) {
        return InvalidIdx;
    }
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return (Length(L)-1);
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return i >= 0 && i < MaxEl;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return (i>=0 && i<Length(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    int i;
    for (i = 0; i <= LastIdx(L); i++) {
        if (L.A[i] == X) {
            return true;
        }
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    if (IsEmpty == false){
        int i;
        for (i = LastIdx(*L); i >= 0; i--) {
            L->A[i + 1] = L->A[i];
        }
    }
    L->A[0] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    int j;
    if (IsIdxValid(*L, i)) {
        for (j = LastIdx(*L); j >= i; j--) {
            L->A[j + 1] = L->A[j];
            }
        L->A[i] = X;
    }
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    if (IsEmpty(*L)){
        L->A[0] = X;
    }
    else {
        L->A[LastIdx(*L) + 1] = X;
    }
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    for (int i = 0; i <= LastIdx(*L); i++){
        L->A[i] = L->A[i + 1];
    }
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    if (IsIdxEff(*L, i)) {
        for (int j = i; j <= LastIdx(*L); j++) {
            L->A[j] = L->A[j + 1];
        }
    }
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    int i = LastIdx(*L);

    L->A[i] = Mark;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2) {
    List L3 = MakeList();  // Membuat list baru untuk hasil penggabungan
    int i, j;
    
    // Tambahkan elemen-elemen dari L1 ke L3
    for (i = 0; i < Length(L1); i++) {
        L3.A[i] = L1.A[i];
    }
    
    // Tambahkan elemen-elemen dari L2 ke L3
    for (j = 0; j < Length(L2) && i < MaxEl; j++, i++) {
        L3.A[i] = L2.A[j];
    }
    
    return L3;  // Mengembalikan list gabungan
}

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
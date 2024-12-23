#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List L;
    int i;

    for (i = 0; i < MaxEl; i++) {
        L.A[i].money = Mark;
    }
    
    return L;
}

/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return L.A[0].money == Mark;  
}

/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return L.A[i];
}

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
        if (L.A[i].money != Mark) {  
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

IdxType LastIdx(List L){
    return (Length(L) - 1);
}

/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(IdxType i){
    return i >= 0 && i < MaxEl;
}

boolean IsIdxEff(List L,IdxType i){
    return i >= 0 && i < Length(L);
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X) {
    int i;
    for (i = 0; i <= LastIdx(L); i++) {
        if (L.A[i].money == X.money && 
            myStrcmp(L.A[i].name, X.name) == 0 && 
            myStrcmp(L.A[i].password, X.password) == 0) {  
            return true;  
        }
    }
    return false; 
}

/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    int i;
    for (i = LastIdx(*L); i >= 0; i--) {
        L->A[i + 1] = L->A[i];  
    }
    L->A[0] = X;  
}

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    int j;
    if (IsIdxValid(i)) {
        for (j = LastIdx(*L); j >= i; j--) {
            L->A[j + 1] = L->A[j];  
        }
        L->A[i] = X;  
    }
}

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    L->A[LastIdx(*L) + 1] = X;  
}

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    int i;
    for (i = 0; i < LastIdx(*L); i++) {
        L->A[i] = L->A[i + 1];  
    }
    L->A[LastIdx(*L)] = (User){.money = Mark};  
}

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    int j;
    if (IsIdxEff(*L, i)) {
        for (j = i; j < LastIdx(*L); j++) {
            L->A[j] = L->A[j + 1];  
        }
        L->A[LastIdx(*L)] = (User){.money = Mark};  
    }
}

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    L->A[LastIdx(*L)] = (User){.money = Mark}; 
}

/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2) {
    List L3 = MakeList();  
    int i, j;
    
    
    for (i = 0; i < Length(L1); i++) {
        L3.A[i] = L1.A[i];
    }
    
    
    for (j = 0; j < Length(L2) && i < MaxEl; j++, i++) {
        L3.A[i] = L2.A[j];
    }
    
    return L3;  
}

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */

/* fungsi strcmp tanpa menggunakan string.h */
/* mengembalikan 1 jika string TIDAK sama dan 0 jika iya */
int myStrcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 1;  
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;  
    }
    return 1;  
}
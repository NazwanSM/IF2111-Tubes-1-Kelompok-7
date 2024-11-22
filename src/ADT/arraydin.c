
#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (elType *) malloc(InitialSize * sizeof(elType)); 
    array.Capacity = InitialSize;  
    array.Neff = 0; 
    return array;  
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean isEmpty(ArrayDin array){
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
elType get(ArrayDin array, idxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int getCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void insertAt(ArrayDin *array, elType el, idxType i){
    if (array->Neff >= array->Capacity) {
        array->Capacity *= 2;
        array->A = (elType *) realloc(array->A, array->Capacity * sizeof(elType));
    }
    for (int j = array->Neff; j > i; j--){
        array->A[j] = array->A[j - 1];
    }
    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void deleteAt(ArrayDin *array, idxType i){
    for (int j = i; j < length(*array) - 1; j++){
        array->A[j] = array->A[j + 1];
    }
    array->Neff--;
}

#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = NilM;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == NilM;
}

boolean IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int i;
    for (i = 0; i < M.Count; i++) {
        if (manualStrCmp(M.Elements[i].Key.name, k.name) == 0) {
            return M.Elements[i].Value;
        }
    }
    return Undefined;
}

void InsertMap(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
if (!IsFull(*M)) {
        int i;

        for (i = 0; i < M->Count; i++) {
            if (manualStrCmp(M->Elements[i].Key.name, k.name) == 0) {

                M->Elements[i].Value = v;
                return;
            }
        }

        M->Elements[M->Count].Key = k;
        M->Elements[M->Count].Value = v;
        M->Count++;
    }
}
void DeleteMap(Map *M, keytype k)
/* Menghapus Elemen dari Map M. */
/* I.S. M tidak kosong
        elemen dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. elemen dengan key k bukan anggota dari M */
{
    int idx = -1;
    for (int i = 0; i < M->Count; i++) {
        if (manualStrCmp(M->Elements[i].Key.name, k.name) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return;

    for (int i = idx; i < M->Count - 1; i++) {
        M->Elements[i] = M->Elements[i + 1];
    }

    M->Count--;
}


boolean IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i;
    for (i = 0; i < M.Count; i++) {
        if (manualStrCmp(M.Elements[i].Key.name, k.name) == 0) {
            return true;
        }
    }
    return false;
}
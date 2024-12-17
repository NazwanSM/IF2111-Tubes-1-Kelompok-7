/* File: setmap.c */
#include "setmap.h"

void CreateEmptySetMap(SetMap *sm) {
    sm->Count = NilM;
}

boolean IsSetMapEmpty(SetMap sm) {
    return sm.Count == NilM;
}

boolean IsSetMapFull(SetMap sm) {
    return sm.Count == MaxEl;
}

boolean IsMemberSetMap(SetMap sm, keytype k) {
    int i;
    for (i = 0; i < sm.Count; i++) {
        if (strcmp(sm.Elements[i].Key.name, k.name) == 0) {
            return true;
        }
    }
    return false;
}

void InsertSetMap(SetMap *sm, keytype k, valuetype v) {
    if (!IsSetMapFull(*sm)) {
        int i;
        // Cek apakah key sudah ada
        for (i = 0; i < sm->Count; i++) {
            if (strcmp(sm->Elements[i].Key.name, k.name) == 0) {
                // Update value jika key sudah ada
                sm->Elements[i].Value = v;
                return;
            }
        }
        // Tambahkan item baru jika key belum ada
        sm->Elements[sm->Count].Key = k;
        sm->Elements[sm->Count].Value = v;
        sm->Count++;
    }
}

void DeleteSetMap(SetMap *sm, keytype k) {
    int i, j;
    for (i = 0; i < sm->Count; i++) {
        if (strcmp(sm->Elements[i].Key.name, k.name) == 0) {
            // Geser semua elemen setelah i ke kiri
            for (j = i; j < sm->Count - 1; j++) {
                sm->Elements[j] = sm->Elements[j + 1];
            }
            sm->Count--;
            return;
        }
    }
}

valuetype ValueOfSetMap(SetMap sm, keytype k) {
    int i;
    for (i = 0; i < sm.Count; i++) {
        if (strcmp(sm.Elements[i].Key.name, k.name) == 0) {
            return sm.Elements[i].Value;
        }
    }
    return Undefined;
}

void PrintSetMap(SetMap sm) {
    if (IsSetMapEmpty(sm)) {
        printf("SetMap kosong\n");
        return;
    }

    int i;
    for (i = 0; i < sm.Count; i++) {
        printf("%s: %d\n", sm.Elements[i].Key.name, sm.Elements[i].Value);
    }
}

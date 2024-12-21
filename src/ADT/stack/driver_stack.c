#include <stdio.h>
#include "stack.h"

int main(){
    Stack S, copy;
    infotypeStack tes, tes2;

    // Membuat stack kosong
    CreateEmptyStack(&S);
    CreateEmptyStack(&copy);
    if (IsEmptyStack(S)){
        printf("Stack Kosong\n");
    }

    // Mengisi stack
    for (int i = 0; i < 5; i++) {
        tes.biaya = i + 5;
        tes.items = i;
        tes.Key = NULL;
        tes.Value = NULL;
        tes.total = NULL;

        Push(&S, tes);
        printf("Pushed: biaya=%d, items=%d\n", tes.biaya, tes.items);
    }

    printf("\nElemen puncak Stack: biaya=%d, items=%d\n", InfoTop(S).biaya, InfoTop(S).items);


    if (!IsEmptyStack(S)){
        printf("Stack Tidak Kosong\n");
    }

    // Melakukan copy stack
    if (IsEmptyStack(copy)){
        printf("Stack Copy Kosong\n");
    }

    CopyStack(&S, &copy);

    if (!IsEmptyStack(copy)){
        printf("Stack Copy Tidak Kosong\n");
    }

    // Mengosongkan stack
    while (!IsEmptyStack(S)) {
        Pop(&S, &tes2);
    }

    if (IsEmptyStack(S)){
        printf("Stack sudah kosong, pop berhasil\n");
    }
}
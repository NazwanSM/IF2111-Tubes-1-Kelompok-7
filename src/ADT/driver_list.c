#include <stdio.h>
#include "list.h"

int main(){
    List L = MakeList();

    printf("Apakah kosong?\n");
    if (IsEmpty(L)) {
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    // Menambahkan elemen ke dalam list
    User user1 = {.name = "akun", .money = 1000, .password = "pass1"};
    User user2 = {.name = "admin", .money = 2000, .password = "pass2"};
    User user3 = {.name = "alstrukdat", .money = 1500, .password = "pass3"};

    InsertFirst(&L, user1);
    InsertLast(&L, user2);
    InsertAt(&L, user3, 1);

    printf("Banyak elemen: %d\n", Length(L));

    printf("Isi list:\n");
    for (int i = 0; i < Length(L); i++) {
        User user = Get(L, i);
        printf("User %d: %s, %d, %s\n", i, user.name, user.money, user.password);
    }

    printf("FirstIdx: %d\n", FirstIdx(L));
    printf("Get: %d\n", Get(L, 0).money);
    ElType v = {"A", "B", 100};
    Set(&L, 0, v);
    printf("Get: %d\n", Get(L, 0).money);
    
    DeleteAt(&L, 0);
    printf("Isi list:\n");
    for (int i = 0; i < Length(L); i++) {
        User user = Get(L, i);
        printf("User %d: %s, %d, %s\n", i, user.name, user.money, user.password);
    }
    printf("\n");

    List L1 = MakeList();
    List L2 = MakeList();

    InsertLast(&L1, user1);
    InsertLast(&L2, user2);
    List L3 = Concat(L1, L2);

    printf("Isi list gabungan:\n");
    for (int i = 0; i < Length(L3); i++) {
        User user = Get(L3, i);
        printf("User %d: %s, %d, %s\n", i, user.name, user.money, user.password);
    }
    return 0;
}
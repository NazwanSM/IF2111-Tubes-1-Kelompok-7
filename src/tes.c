#include <stdio.h>
#include "storeList.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/boolean.h"
#include "ADT/list.h"
#include "ADT/custom.h"

int main(){
    Barang list[] = {
        {"Laptop", 15000000},
        {"Smartphone", 7000000},
        {"Headset", 300000},
        {"Mouse", 200000},
        {"Keyboard", 500000}
    };

    printf(list[0].name);
}
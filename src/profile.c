#include <stdio.h>
#include "profile.h"

void profile(List user, int userIdx){
    printf("\033[1;32mUsername: %s\033[0m\n", user.A[userIdx].name);
    printf("\033[1;32mMoney: %d\033[0m\n\n", user.A[userIdx].money);
}
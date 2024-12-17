#include <stdio.h>
#include "profile.h"

void profile(List user, int userIdx){
    printf(COLOR_BOLD_YELLOW"Username: "COLOR_OFF COLOR_BOLD_CYAN"%s\n", user.A[userIdx].name);
    printf(COLOR_BOLD_YELLOW"Money: "COLOR_OFF COLOR_BOLD_CYAN"%d\n\n", user.A[userIdx].money);
}
#include <stdio.h>
#include "logout.h"


void logoutUser(int *userIdx, List user) {
    printf("%s telah logout dari sistem PURRMART\n", user.A[*userIdx].name);
    printf("Silakan REGISTER/LOGIN kembali untuk melanjutkan\n");
}
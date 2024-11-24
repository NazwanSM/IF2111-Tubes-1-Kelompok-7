#include <stdio.h>
#include "logout.h"


void logoutUser(int *userIdx, List user) {
    userIdx = -1;
    printf("%s telah logout dari sistem PURRMART.", user.A[*userIdx].name);
    printf("Silakan REGISTER/LOGIN kembali untuk melanjutkan.");
}
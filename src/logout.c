#include <stdio.h>
#include "logout.h"


void logoutUser(int *userIdx, List user) {
    printf(COLOR_BOLD_BLUE"%s "COLOR_OFF"telah logout dari sistem PURRMART\n", user.A[*userIdx].name);
    printf("Silakan REGISTER/LOGIN kembali untuk melanjutkan\n");
}
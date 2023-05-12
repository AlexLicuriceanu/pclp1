#include <stdio.h>
#include "autentificare.h"

int status = 0;
int getStatus() {
    return status;
}

void login(int username, int password) {
    int r;
    while(password)
    {
        r = username % password;
        username = password;
        password = r;
    }

    if (username == 1) {
        status = 1;
        printf("Autentificare cu succes!");
    }
    else
        printf("Autentificare esuata!");
}

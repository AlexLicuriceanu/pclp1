#include <stdio.h>

int main() {
    unsigned int numar;
    scanf_s("%u", &numar);

    char *addr = (char *)&numar;
    if (*addr)
        printf("Little endian.");
    else
        printf("Big endian.");
    return 0;
}

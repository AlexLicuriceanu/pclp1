#include <stdio.h>

int main() {
    int numar;
    printf("Introduceti un numar natural in baza 10: ");
    scanf("%d", &numar);

    printf("Valoarea numarului in baza 8 este: %o\n", numar);
    printf("Valoarea numarului in baza 10 este: %d\n", numar);
    printf("Valoarea numarului in baza 16 este: %X\n", numar);

    return 0;
}
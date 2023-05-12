#include <stdio.h>

int main() {
    unsigned int a, b, c;

    // Citirea numerelor de la tastatura
    printf("Introduceti cele 3 laturi ale triunghiului: ");
    scanf("%u %u %u", &a, &b, &c);

    // Verificarea condițiilor pentru a forma un triunghi
    if ((a + b > c) && (b + c > a) && (a + c > b)) {
        printf("DA\n");
    } else {
        printf("NU\n");
    }

    return 0;
}

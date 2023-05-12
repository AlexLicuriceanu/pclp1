#include <stdio.h>

int main() {
    int n;
    printf("Introduceti un numar natural: ");
    scanf("%d", &n);

    int suma1 = n * (n + 1) / 2;
    int suma2 = n * (n + 1) * (2*n + 1) / 6;

    printf("S1: %d\n", suma1);
    printf("S2: %d\n", suma2);

    return 0;
}
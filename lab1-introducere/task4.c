#include <stdio.h>

int main() {
    double numar1, numar2, suma, diferenta, medie;
    printf("Introduceti primul numar: ");
    scanf("%lf", &numar1);
    printf("Introduceti al doilea numar: ");
    scanf("%lf", &numar2);

    suma = numar1 + numar2;
    diferenta = numar1 - numar2;
    medie = (numar1 + numar2) / 2;

    printf("Suma celor doua numere este: %.5lf\n", suma);
    printf("Diferenta celor doua numere este: %.5lf\n", diferenta);
    printf("Media celor doua numere este: %.5lf\n", medie);

    return 0;
}
#include <stdio.h>

int main() {
    int num;

    // Citeste un numar intreg de la tastatura
    printf("Introduceti un numar intreg: ");
    scanf("%d", &num);

    // Verificare folosind operatorul modulo (%)
    if (num % 2 == 0) {
        printf("%d este un numar par (verificare cu modulo)\n", num);
    } else {
        printf("%d este un numar impar (verificare cu modulo)\n", num);
    }

    // Verificare folosind operatia bit a doua (&)
    if ((num & 1) == 0) {
        printf("%d este un numar par (bitwise)\n", num);
    } else {
        printf("%d este un numar impar (bitwise)\n", num);
    }

    return 0;
}

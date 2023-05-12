#include <stdio.h>
#include <math.h>

int main() {
    double a, b, diff;
    printf("Introduceti primul numar: ");
    scanf("%lf", &a);
    printf("Introduceti al doilea numar: ");
    scanf("%lf", &b);

    diff = fabs(a - b);

    if (diff <= 0.0001) {
        printf("EQ\n");
    } else {
        printf("NOT EQ\n");
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, min, max;
    printf("Introduceti primul numar: ");
    scanf("%lf", &a);
    printf("Introduceti al doilea numar: ");
    scanf("%lf", &b);

    if (fabs(a) < fabs(b)) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }

    printf("Minimul este: %.2lf\n", min);
    printf("Maximul este: %.2lf\n", max);

    return 0;
}
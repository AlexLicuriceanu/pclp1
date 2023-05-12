#include <stdio.h>
#include "math.h"

int main() {
    int a, b, c, u, v;
    scanf_s("%d%d%d%d%d", &a, &b, &c, &u, &v);

    int min = a*u+b;
    int max = a*v+b;
    printf("Min: %d, Max: %d\n", min, max);

    float x1 = (float)(-b+(sqrt(pow(b, 2)-4*a*c)))/(2*a);
    float x2 = (float)(-b-(sqrt(pow(b, 2)-4*a*c)))/(2*a);
    if ((float)u<=x1 && x1<=(float)v) printf("%f ", x1);
    if ((float)u<=x2 && x2<=(float)v) printf("%f", x2);
    return 0;
}
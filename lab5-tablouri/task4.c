#include <stdio.h>

#define MAX 20

int main() {
    int v[MAX] = {0}, dim = 0;

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0)
            break;
        else {
            v[i] = val;
            dim++;
        }
    }

    float sum = 0; int counter = 0;
    for (int i=0; i<dim; i++) {
        if (v[i] % 2 == 0) {
            sum += v[i];
            counter++;
        }
    }

    if (counter == 0)
        printf("Nu exista elemente pare");
    else
        printf("%f\n", sum / counter);
    return 0;
}

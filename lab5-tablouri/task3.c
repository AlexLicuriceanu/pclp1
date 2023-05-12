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

    if (v[0] > v[1]) printf("%d ", v[0]);
    for (int i=1; i<dim-1; i++) {
        if (v[i] > v[i+1] && v[i] > v[i-1])
            printf("%d ", v[i]);
    }
    if (v[dim-1] > v[dim-2] && dim > 1) printf("%d ", v[dim-1]);
    return 0;
}

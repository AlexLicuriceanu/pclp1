#include <stdio.h>

#define MAX 20

int main() {
    int v[MAX] = {0};

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0)
            break;
        else
            v[i] = val;
    }

    for (int i=0; i<MAX; i++) {
        if (v[i] > i)
            printf("%d ", v[i]);
    }
    return 0;
}

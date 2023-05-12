#include <stdio.h>

#define MAX 20

int main() {
    int v[MAX+1] = {0};
    for (int i=1; i<=MAX; i++)
        v[i] = i;
    v[1] = 0;

    for(int i = 2; i*i <= MAX; i++) {
        if(v[i] != 0) {
            for(int j = 2*i; j<=MAX; j+=i) {
                v[j] = 0;
            }
        }
    }
    for (int i=1; i<=MAX; i++) {
        if (v[i]!=0)
            printf("%d ", i);
    }
    return 0;
}

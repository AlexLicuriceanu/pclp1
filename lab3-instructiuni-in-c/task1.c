#include <stdio.h>

int main() {
    unsigned int N;
    scanf_s("%u", &N);

    unsigned int nmax = 0, smax = 0;
    for(int i=2; i<=N; i++) {
        int suma = 0;
        for (int j=2; j<=i/2; j++) {
            if (i%j==0) suma += j;
        }
        if(suma > smax) {
            nmax = i;
            smax = suma;
        }
    }
    printf("%u", nmax);
    return 0;
}
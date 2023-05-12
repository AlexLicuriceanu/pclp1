#include <stdio.h>

void is_even(int n) {
    if (n & 1) printf("Impar\n");
    else printf("Par\n");
}

unsigned int pow2(int n) {
    unsigned int b = 1;
    return b << n;
}

unsigned int flip_bits(int n) {
    return ~n+1;
}

void print_bits(unsigned int n){
    unsigned int mask = 2147483648;
    while (mask) {
        if ((mask & n) == 0) printf("0");
        else printf("1");
        mask >>= 1;
    }
}

int is_power2 (int n) {
    if (!(n & n-1)) return 1;
    else return 0;
}

void alterneaza(unsigned int n) {
    int x = n ^ (n >> 1);
    if ((x+1 & x) == 0) printf("Alterneaza.");
    else printf("Nu alterneaza.");

}

void bit_mic_mare (int n) {
    unsigned int nr = 0;
    for (int i=0; i<n; i++) {
        nr += pow2(i);
    }
    printf("%d ", nr);
    for (int i=31; i>=31-n+1; i--) {
        nr += pow2(i);
    }
    printf("%u \n\n", nr);
}

int schimba_biti(int n, int m) {
    int nr = n ^ m;
    int count = 0;
    while (nr > 0)
    {
        count++;
        nr &= (nr-1);
    }
    return count;
}
int main() {
    printf("1. Se dau doua numere N si M. Sa se determine cati biti ar trebui sa fie\n"
           "schimbati in N pentru a deveni egal cu M.\n"
           "Input:\n");
    unsigned int n, m; scanf("%u %u", &n, &m);
    printf("Output:\n %d \n\n", schimba_biti(n, m));

    printf("2. Se da un numar N. Sa se verifice daca in N toti bitii alterneaza pana la cel\n"
           "mai din stanga bit setat. (nu exista 1 bit de 1 langa un bit de 1 sau un bit de\n"
           "0 langa unul de 0). Se va scrie alterneaza/nu alterneaza in functie de rezultat.\"|\"\n"
           "Input:\n");
    scanf("%u", &n);
    printf("Output:\n"); alterneaza(n); printf("\n\n");

    printf("3. Se da un numar N. Sa se determine cel mai mic si cel mai mare numar intreg care\n"
           "poate fi format cu un numar egal de biti de 1 si 0.\"|\"\n"
           "Input:\n");
    scanf("%u", &n);
    printf("Output:\n"); bit_mic_mare(n);
    return 0;
}

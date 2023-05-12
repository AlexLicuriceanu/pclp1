#include <stdio.h>

unsigned int getBits(unsigned int nr, int k, int pos) {
    return (((1 << k) - 1) & (nr >> (pos-1)));
}

int main() {
    unsigned int inst = 0;
    scanf("%u", &inst);
    unsigned int N = getBits(inst, 3, 30) + 1;
    printf("%d ", N);

    unsigned int operatii = getBits(inst, 2*N, 30-2*N);
    char op[16];
    int op_k = 0;

    for (int i = N-1; i >= 0; i--) {
        unsigned int tmp_operator = getBits(operatii, 2, 1+op_k);
        if (tmp_operator == 0)
            op[i] = '+';
        else if (tmp_operator == 1)
            op[i] = '-';
        else if (tmp_operator == 2)
            op[i] = '*';
        else if (tmp_operator == 3)
            op[i] = '/';
        op_k += 2;
    }

    for (int i = 0; i < op_k/2; i++)
        printf("%c ", op[i]);

    unsigned int dim = getBits(inst, 4, 26-2*N) + 1;
    printf("%u\n", dim);
    return 0;
}
#include <stdio.h>

unsigned int getBits(unsigned int nr, int k, int pos) {
    return (((1 << k) - 1) & (nr >> (pos-1)));
}

int main() {
    unsigned int inst = 0;
    scanf("%u", &inst);
    unsigned int N = getBits(inst, 3, 30) + 1;
    // printf("%d ", N); // task1

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

    unsigned int dim = getBits(inst, 4, 26-2*N) + 1;
    // printf("%u ", dim); // task1

    int numere = ((N+1) * dim) / 16;
    if (((N + 1) * dim) % 16 != 0) numere++;

    int counter = 0, v[128] = {0};
    for (int i = 0; i < numere; i++) {
        unsigned short val;
        scanf("%hu", &val);

        int step = 0;
        while (counter < N+1 && step < 16) {
            v[counter] = getBits(val, dim, 16-dim-step+1);
            step += dim;
            counter++;
        }
    }

    int rez = v[0];
    for (int i = 1; i< N+1; i++) {
        if (op[i-1] == '+')
            rez += v[i];
        else if (op[i-1] == '-')
            rez -= v[i];
        else if (op[i-1] == '*')
            rez *= v[i];
        else if (op[i-1] == '/' && v[i] != 0)
            rez /= v[i];
    }
    printf("%d\n", rez);
    return 0;
}
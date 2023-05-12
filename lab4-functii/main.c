#include <stdio.h>
#include "autentificare.h"

int factorial_iterativ(int n) {
    int p = 1;
    for (int i=1; i<=n; i++)
        p *= i;
    return p;
}

int factorial_recursiv(int n) {
    if (n == 1) return 1;
    else return n * factorial_recursiv(n-1);
}

int suma_cifre_recursiv(int n) {
    if (n==0) return 0;
    else return n%10 + suma_cifre_recursiv(n/10);
}

int suma_cifre_iterativ(int n) {
    int s = 0;
    while (n) {
        s += n%10;
        n /= 10;
    }
}

int este_prim(int n) {
    int div = 0;
    for(int i=2; i<=n/2; i++) {
        if (n%i == 0) div++;
    }
    if (div == 0) return 1;
    else return 0;
}

int este_palindrom(int n) {
    int cn = n, x = 0;
    while(cn) {
        x = x*10+cn%10;
        cn /= 10;
    }
    if (x == n) return 1;
    else return 0;
}

void div_palindrom(int n) {
    int k = 0;
    for (int i=1; i<= n; i++) {
        if (n%i==0 && este_palindrom((i))) {
            k++;
            printf("%d ", i);
        }
    }
    printf("Total: %d divizori care sunt nr. palindrom", k);
}

int citire_contor (int k) {
    int nr; scanf("%d", &nr);
    if(nr == 0) return k;
    else if (nr > 0 && este_prim(nr)) {
        return citire_contor(k+1);
    }
    else return citire_contor(k);
}

int main() {
    int username, password;
    scanf("%d %d", &username, &password);
    login(username, password);
    printf("\n%d", getStatus());
    return 0;
}

#include <stdio.h>

int main() {
    int nr=0, kprim=0;

    while (nr>=0) {
        scanf_s("%d", &nr);

        if (nr < 0) break;
        else {
            int kdiv = 0;
            for (int i=2; i<=nr/2; i++) {
                if (nr%i==0) {
                    kdiv++;
                    printf("%d ", i);
                }
            }
            if (kdiv==0)  {
                printf("PRIM\n");
                kprim++;
            }
            else printf("\n");
        }
    }
    printf("S-au gasit %d numere prime.", kprim);
    return 0;
}
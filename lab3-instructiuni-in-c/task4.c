#include <stdio.h>

int main() {
    int nr=0;
    while (nr>=0) {
        scanf_s("%d", &nr);

        int bin[32] = {0};
        if (nr<0) break;
        else {
            int start = 31;
            for(int i=31; i>=0 && nr > 0; i--) {
                bin[i] = nr % 2;
                nr /= 2;
                start = i;
            }
            for (int j=start; j<32; j++)
                printf("%d", bin[j]);
            printf("\n");
        }
    }

    return 0;
}
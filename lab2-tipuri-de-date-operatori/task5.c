#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inițializarea seed-ului cu ora curentă a sistemului
    srand(time(NULL));

    // Generarea și afișarea a 5 numere aleatoare
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand());
    }

    printf("\n");
    return 0;
}

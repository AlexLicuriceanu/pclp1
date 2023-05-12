#include <stdio.h>
#include <unistd.h>

int main() {
    int i;

    // Numarare descrescatoare de la 3 la 1
    for (i = 3; i >= 1; i--) {
        printf("%d\n", i);
        sleep(1); // Asteapta o secunda
    }

    // Afisare mesaj START
    printf("START\n");

    return 0;
}

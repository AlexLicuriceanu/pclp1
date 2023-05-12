#include <stdio.h>

int main() {
    int nr;
    scanf_s("%d", &nr);

    int cnr = nr, t=0;
    while(nr>0) {
        t = t*10 + nr % 10;
        nr /= 10;
    }
    if (t==cnr) printf("Palindrom.");
    else printf("Nu este palindrom.");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "./functii_str.h"

#define MAX 1024

int main() {
    char *sir = malloc((MAX+1) * sizeof(char));
    fgets(sir, MAX+1, stdin);

    printf("Select: ");
    int task_nr = 0, pos = 0, n = 0;;
    scanf_s("%d", &task_nr);

    if (task_nr == 1)
        printf("%d\n", str_length(sir));

    else if (task_nr == 2) {
        scanf_s("%d%d", &pos, &n);
        char *rez_str = strdel(sir, pos-1, n);

        printf("%s", rez_str);
        free(rez_str);
    }

    else if (task_nr == 3) {
        scanf_s("%d", &pos);
        char sir2[MAX+1];
        fgets(sir2, MAX+1, stdin);

        sir = strins(sir, pos, sir2);
        printf("%s", sir);
        free(sir);
    }

    else if (task_nr == 4) {
        char *mask = malloc((MAX+1) * sizeof(char));
        fgets(mask, MAX+1, stdin);
        printf("Is mask: %d", eq_mask(sir, mask));
        free(mask);
    }

    else if (task_nr == 5) {
        char *tablou[100] = {"curs1", "curs2", "curs3"};
        char *cuv1 = "curs2", *cuv2 = "curs5";
        printf("curs2 %s in tablou\n",(eqcuv(cuv1, tablou)) ? "este" : "nu este");
        printf("curs5 %s in tablou\n",(eqcuv(cuv2, tablou)) ? "este" : "nu este");
    }
    return 0;
}

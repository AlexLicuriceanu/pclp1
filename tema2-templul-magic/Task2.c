#include "./utils.h"

#define MAX 1000
#define LOW 10

void input(char *string, int length) {
    fgets(string, length, stdin);

    for (int i = 0; i <= length; i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
    }
}

char rotCaesar(char caracter, int key, char start, char final) {
    while (key != 0) {
        if (caracter == start) {
            caracter = final;
            key--;
        } else {
            caracter--;
            key--;
        }
    }
    return caracter;
}

void descifrareCaesar(char *sir, int key) {
    for (int i = 0; i < strlen(sir); i++) {
        if (sir[i] >= '0' && sir[i] <= '9') {
            sir[i] = rotCaesar(sir[i], key, '0', '9');
        } else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = rotCaesar(sir[i], key, 'A', 'Z');
        } else if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = rotCaesar(sir[i], key, 'a', 'z');
        }
    }
}

void swapVectors(char *v1, char *v2) {
    char *aux = malloc((strlen(v1)+1) * sizeof(char));
    snprintf(aux, MAX+1, "%s", v1);
    snprintf(v1, MAX+1, "%s", v2);
    snprintf(v2, MAX+1, "%s", aux);
    free(aux);
}

void strrev_s(char *s) {
    char *start = s, *final = s, aux = 0;

    for (int i = 0; i < strlen(s)-1; i++)
        final++;

    for (int i = 0; i < strlen(s)/2; i++) {
        aux = *final;
        *final = *start;
        *start = aux;

        start++;
        final--;
    }
}

void addVectors(char v1[], char v2[]) {
    if (strlen(v1) > strlen(v2))
        swapVectors(v1, v2);

    char *result = malloc(sizeof(char) * (strlen(v1)+ strlen(v2)+1));
    snprintf(result, MAX+1, "%d", '\0');
    int len_v1 = (int)strlen(v1), len_v2 = (int)strlen(v2), carry = 0;
    strrev_s(v1);
    strrev_s(v2);

    for (int i = 0; i < len_v1; i++) {
        int suma = (v1[i]-'0') + (v2[i]-'0') + carry;
        snprintf(result+strlen(result), MAX+1, "%d", suma%LOW);
        carry = suma / LOW;
    }

    for (int i = len_v1; i < len_v2; i++) {
        int suma = (v2[i]-'0') + carry;
        snprintf(result+strlen(result), MAX+1, "%d", suma%LOW);
        carry = suma / LOW;
    }

    if (carry)
        snprintf(result+strlen(result), MAX+1, "%d", carry);
    strrev_s(result);
    snprintf(result+strlen(result)-1, MAX+1, "%s", result+strlen(result));

    int start_pos = 0;
    for (int i = 0; i < strlen(result); i++) {
        if (result[i] == '0')
            start_pos++;
        else
            break;
    }

    printf("%s", result+start_pos);
    free(result);
}

void SolveTask2() {
    getchar();
    char tip_cifru[LOW];
    input(tip_cifru, LOW);

    if (strcmp("caesar", tip_cifru) == 0) {
        int key = 0;
        scanf("%d", &key);
        getchar();

        char sir[MAX+1];
        input(sir, MAX+1);

        descifrareCaesar(sir, key);
        printf("%s", sir);

    } else if (strcmp("vigenere", tip_cifru) == 0) {
        char key[LOW];
        input(key, LOW);

        char sir[MAX+1];
        input(sir, MAX+1);

        for (int i = 0; i < strlen(sir); i++) {
            unsigned int arg = (strlen(key)+i)%strlen(key);
            if (sir[i] >= '0' && sir[i] <= '9') {
                sir[i] = rotCaesar(sir[i], key[arg]-'A', '0', '9');
            } else if (sir[i] >= 'a' && sir[i] <= 'z') {
                sir[i] = rotCaesar(sir[i], key[arg]-'A', 'a', 'z');
            } else if (sir[i] >= 'A' && sir[i] <= 'Z') {
                sir[i] = rotCaesar(sir[i], key[arg]-'A', 'A', 'Z');
            }
        }
        printf("%s", sir);

    } else if (strcmp("addition", tip_cifru) == 0) {
        int key = 0;
        scanf("%d\n", &key);

        char N1[MAX+1], N2[MAX+1];
        input(N1, MAX+1);
        input(N2, MAX+1);

        descifrareCaesar(N1, key);
        descifrareCaesar(N2, key);

        addVectors(N1, N2);
    }
    printf("\n");
}

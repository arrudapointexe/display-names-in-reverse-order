#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int main() {
    char *nomes[5];

    for (int i = 0; i < 5; i++) {
        nomes[i] = (char *)malloc(TAM * sizeof(char));

        if (nomes[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(nomes[i], TAM, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    printf("\nNomes em ordem inversa:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%s\n", nomes[i]);
    }

    for (int i = 0; i < 5; i++) {
        free(nomes[i]);
    }

    return 0;
}


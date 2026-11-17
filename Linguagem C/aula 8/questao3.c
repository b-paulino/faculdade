/* A interpretacao das correspondencias esta explicada no README. */
#include <stdio.h>
#include <stdlib.h>

int primo(int numero) {
    int i;
    if (numero < 2) {
        return 0;
    }
    for (i = 2; i <= numero / i; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int *numeros = malloc(15 * sizeof(int));
    int ocorrencias[15];
    int i, j, repetido, total = 0;
    char **animais;
    if (numeros == NULL) {
        exit(1);
    }
    for (i = 0; i < 15; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    printf("\nNumeros repetidos:\n");
    for (i = 0; i < 15; i++) {
        ocorrencias[i] = 0;
        for (j = 0; j < 15; j++) {
            if (numeros[i] == numeros[j]) {
                ocorrencias[i]++;
            }
        }
        /* Conta em todas as posicoes, mas processa cada numero uma vez. */
        repetido = 0;
        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                repetido = 1;
            }
        }
        if (repetido == 0 && ocorrencias[i] > 1) {
            printf("%d: %d ocorrencias\n", numeros[i], ocorrencias[i]);
            if (primo(numeros[i]) && ocorrencias[i] % 2 != 0) {
                if (numeros[i] > (1000 - total) / ocorrencias[i]) {
                    printf("Esta versao aceita ate 1000 animais.\n");
                    exit(1);
                }
                total += numeros[i] * ocorrencias[i];
            }
        }
    }
    animais = malloc((total + 1) * sizeof(char *));
    if (animais == NULL) {
        exit(1);
    }
    printf("\nTotal de animais para cadastrar: %d\n", total);
    for (i = 0; i < total; i++) {
        animais[i] = malloc(80 * sizeof(char));
        if (animais[i] == NULL) {
            exit(1);
        }
        printf("Animal %d: ", i + 1);
        scanf(" %79[^\n]", animais[i]);
    }
    printf("\nAnimais cadastrados:\n");
    for (i = 0; i < total; i++) {
        printf("%d. %s\n", i + 1, animais[i]);
    }
    printf("\nCorrespondencias pelas posicoes:\n");
    for (i = 0; i < 15; i++) {
        if (ocorrencias[i] % 2 == 0) {
            printf("Posicao %d, numero %d: ", i + 1, numeros[i]);
            if (i < total) {
                printf("%s\n", animais[i]);
            } else {
                printf("Nao existe correspondencia.\n");
            }
        }
    }
    for (i = 0; i < total; i++) {
        free(animais[i]);
    }
    free(animais);
    free(numeros);
    return 0;
}

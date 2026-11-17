#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Retorna zero se esse numero ja foi contado antes. */
int contar(int *numeros, int posicao) {
    int j, quantidade = 0;
    for (j = 0; j < posicao; j++) {
        if (numeros[j] == numeros[posicao]) {
            return 0;
        }
    }
    for (j = 0; j < 12; j++) {
        if (numeros[j] == numeros[posicao]) {
            quantidade++;
        }
    }
    return quantidade;
}

int main(void) {
    int *numeros = malloc(12 * sizeof(int));
    int *pares = malloc(12 * sizeof(int));
    int ocorrencias[12];
    int i, j, total = 0, qtd_pares = 0, auxiliar;
    char **nomes, *nome_auxiliar;
    double *precos, preco_auxiliar;

    if (numeros == NULL || pares == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for (i = 0; i < 12; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    for (i = 0; i < 12; i++) {
        ocorrencias[i] = contar(numeros, i);
        if (ocorrencias[i] > 0 && ocorrencias[i] % 2 == 0) {
            pares[qtd_pares] = numeros[i];
            qtd_pares++;
        } else if (ocorrencias[i] % 2 != 0 && numeros[i] > 0) {
            if (numeros[i] > 1000 - total) {
                printf("Esta versao aceita ate 1000 produtos.\n");
                exit(1);
            }
            total += numeros[i];
        }
    }
    /* Uma posicao extra evita pedir malloc(0) quando total for zero. */
    nomes = malloc((total + 1) * sizeof(char *));
    precos = malloc((total + 1) * sizeof(double));
    if (nomes == NULL || precos == NULL) {
        exit(1);
    }
    for (i = 0; i < total; i++) {
        nomes[i] = malloc(80 * sizeof(char));
        if (nomes[i] == NULL) {
            exit(1);
        }
        printf("Nome do produto %d: ", i + 1);
        scanf(" %79[^\n]", nomes[i]);
        do {
            printf("Preco: ");
            scanf("%lf", &precos[i]);
        } while (precos[i] < 0);
    }
    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                nome_auxiliar = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = nome_auxiliar;
                preco_auxiliar = precos[i];
                precos[i] = precos[j];
                precos[j] = preco_auxiliar;
            }
        }
    }
    for (i = 0; i < qtd_pares - 1; i++) {
        for (j = i + 1; j < qtd_pares; j++) {
            if (pares[i] < pares[j]) {
                auxiliar = pares[i];
                pares[i] = pares[j];
                pares[j] = auxiliar;
            }
        }
    }
    printf("\nNumeros informados:\n");
    for (i = 0; i < 12; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nOcorrencias:\n");
    for (i = 0; i < 12; i++) {
        if (ocorrencias[i] > 0) {
            printf("%d: %d vez(es)\n", numeros[i], ocorrencias[i]);
        }
    }
    printf("\nProdutos em ordem alfabetica:\n");
    for (i = 0; i < total; i++) {
        printf("%s: R$ %.2f\n", nomes[i], precos[i]);
        free(nomes[i]);
    }
    printf("\nNumeros com ocorrencias pares:\n");
    for (i = 0; i < qtd_pares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");
    free(numeros);
    free(pares);
    free(nomes);
    free(precos);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void ordenar(int *vetor, int quantidade) {
    int i, j, auxiliar;
    for (i = 0; i < quantidade - 1; i++) {
        for (j = i + 1; j < quantidade; j++) {
            if (vetor[i] > vetor[j]) {
                auxiliar = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = auxiliar;
            }
        }
    }
}

void mostrar(int *vetor, int quantidade) {
    int i;
    ordenar(vetor, quantidade);
    for (i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    if (quantidade == 0) {
        printf("Nenhum valor.");
    }
    printf("\n");
}

int main(void) {
    int *pares = malloc(10 * sizeof(int));
    int *impares = malloc(10 * sizeof(int));
    int i, numero, qtd_pares = 0, qtd_impares = 0;
    if (pares == NULL || impares == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);
        if (numero > 0 && numero % 2 == 0) {
            pares[qtd_pares] = numero;
            qtd_pares++;
        } else if (numero < 0 && numero % 2 != 0) {
            impares[qtd_impares] = numero;
            qtd_impares++;
        }
    }
    printf("\nPares positivos:\n");
    mostrar(pares, qtd_pares);
    printf("\nImpares negativos:\n");
    mostrar(impares, qtd_impares);
    free(pares);
    free(impares);
    return 0;
}

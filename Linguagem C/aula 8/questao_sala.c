#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam, i, numero;
    int *pares, *impares;
    int p = 0, y = 0;

    printf("Digite a quantidade de numeros:\n");
    scanf("%d", &tam);

    pares = (int *) malloc(sizeof(int) * tam);
    impares = (int *) malloc(sizeof(int) * tam);

    for (i = 0; i < tam; i++) {
        printf("Digite o numero %d:\n", i + 1);
        scanf("%d", &numero);

        if (numero > 0 && numero % 2 == 0) {
            pares[p] = numero;
            p++;
        }
        else if (numero < 0 && numero % 2 != 0) {
            impares[y] = numero;
            y++;
        }
    }

    printf("\nPares positivos: ");
    for (i = 0; i < p; i++) {
        printf("%d ", pares[i]);
    }

    printf("\nImpares negativos: ");
    for (i = 0; i < y; i++) {
        printf("%d ", impares[i]);
    }

    free(pares);
    free(impares);

    printf("\nQuantidade em p: %d\n", p);
    printf("Quantidade em y: %d\n", y);

    return 0;
}
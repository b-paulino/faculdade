#include <stdio.h>

int ehPrimo(int numero) {
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

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (ehPrimo(numero) == 1) {
        printf("O numero %d e primo.\n", numero);
    } else {
        printf("O numero %d nao e primo.\n", numero);
    }

    return 0;
}

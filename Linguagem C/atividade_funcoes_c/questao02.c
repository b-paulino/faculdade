#include <stdio.h>

int calcularDobro(int numero) {
    return numero * 2;
}

int main() {
    int numero, dobro;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    dobro = calcularDobro(numero);
    printf("O dobro de %d e %d\n", numero, dobro);

    return 0;
}

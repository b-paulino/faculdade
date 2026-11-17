
#include <stdio.h>

int main() {
    int a, b, c;
    int maior, menor, meio;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de C: ");
    scanf("%d", &c);

    maior = a;

    if (b > maior) {
        maior = b;
    }

    if (c > maior) {
        maior = c;
    }

    menor = a;

    if (b < menor) {
        menor = b;
    }

    if (c < menor) {
        menor = c;
    }

    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        meio = a;
    }
    else if ((b >= a && b <= c) || (b >= c && b <= a)) {
        meio = b;
    }
    else {
        meio = c;
    }

    printf("\nMaior valor: %d", maior);
    printf("\nMenor valor: %d", menor);
    printf("\nValor intermediario: %d", meio);

    
    if (a == b || a == c || b == c) {
        printf("\nExistem valores repetidos.");
    }
    else {
        printf("\nNao existem valores repetidos.");
    }

    if (a == b && b == c) {
        printf("\nOs tres valores sao iguais.");
    }
    else {
        printf("\nOs tres valores nao sao iguais.");
    }

    if (a < b && b < c) {
        printf("\nOrdem crescente.");
    }
    else if (a > b && b > c) {
        printf("\nOrdem decrescente.");
    }
    else {
        printf("\nNao estao em ordem crescente nem decrescente.");
    }

    return 0;
}

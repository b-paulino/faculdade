
#include <stdio.h>

int main() {
    int opcao, numero;

    printf("===== MENU =====\n");
    printf("1 - Verificar par ou impar\n");
    printf("2 - Verificar positivo ou negativo\n");
    printf("3 - Calcular o quadrado\n");
    printf("4 - Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            printf("Numero par\n");
        }
        else {
            printf("Numero impar\n");
        }

        if (numero > 0) {
            printf("Numero positivo\n");
        }
        else if (numero < 0) {
            printf("Numero negativo\n");
        }
        else {
            printf("Numero igual a zero\n");
        }
    }
    else if (opcao == 2) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero > 0) {
            printf("Numero positivo\n");
        }
        else if (numero < 0) {
            printf("Numero negativo\n");
        }
        else {
            printf("Numero igual a zero\n");
        }
    }
    else if (opcao == 3) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        printf("Quadrado: %d\n", numero * numero);
    }
    else if (opcao == 4) {
        printf("Programa encerrado!\n");
    }
    else {
        printf("Opcao invalida!\n");
    }

    return 0;
}

#include <stdio.h>

float somar(float num1, float num2) {
    return num1 + num2;
}

float subtrair(float num1, float num2) {
    return num1 - num2;
}

float multiplicar(float num1, float num2) {
    return num1 * num2;
}

float dividir(float num1, float num2) {
    return num1 / num2;
}

int main() {
    float num1, num2, resultado;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    printf("\nEscolha a operacao:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        resultado = somar(num1, num2);
        printf("Resultado: %.2f\n", resultado);

    } else if (opcao == 2) {
        resultado = subtrair(num1, num2);
        printf("Resultado: %.2f\n", resultado);

    } else if (opcao == 3) {
        resultado = multiplicar(num1, num2);
        printf("Resultado: %.2f\n", resultado);

    } else if (opcao == 4) {
        if (num2 != 0) {
            resultado = dividir(num1, num2);
            printf("Resultado: %.2f\n", resultado);
        } else {
            printf("Nao e possivel dividir por zero.\n");
        }
        
    } else {
        printf("Opcao invalida.\n");
    }

    return 0;
}

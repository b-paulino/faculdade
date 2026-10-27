#include <stdio.h>

int ehPar(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    if (ehPar(num) == 1) {
        printf("O numero %d e par\n", num);
    } else {
        printf("O numero %d e impar\n", num);
    }

    return 0;
}

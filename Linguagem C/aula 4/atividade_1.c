
#include <stdio.h>

int main() {
    int saque;

    printf("Digite o valor do saque: R$ ");
    scanf("%d", &saque);

    if (saque <= 0 || saque % 10 != 0) {
        printf("Valor invalido!\n");
    }
    else if (saque == 50) {
        printf("Saque realizado com sucesso!\n");
    }
    else {
        printf("Saque nao pode ser realizado!\n");}

    return 0;
}

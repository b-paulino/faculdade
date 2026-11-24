#include <stdio.h>
#include "meu_banco.h"

int main(void) {
    Cliente clientes[100];
    Conta contas[300];
    int opcao;
    int quantidadeClientes = 0;
    int cadastroFeito = 0;

    do {
        mostrarMenu()ç
        scanf("%d", &opcao);
        
        printf("\n1 - Cadastrar clientes\n");
        printf("2 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (cadastroFeito == 0) {
                    quantidadeClientes = cadastrarClientes(clientes, contas);

                    if (quantidadeClientes > 0) {
                        cadastroFeito = 1;
                        printf("Clientes cadastrados: %d\n",
                               quantidadeClientes);
                    }
                } else {
                    printf("Os clientes ja foram cadastrados.\n");
                }
                break;

            case 2:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 2);

    return 0;
}
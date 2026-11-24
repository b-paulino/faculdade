#include <stdio.h>
#include <string.h>
#include "meu_banco.h"

void mostrarMenu(void) {
    printf("\n1 - Cadastrar clientes\n");
    printf("2 - Sair\n");
    printf("Escolha: ");
}

int cadastrarClientes(Cliente clientes[], Conta contas[]) {
    int quantidade;
    int quantidadeContas;
    int totalContas = 0;
    int numeroConta = 1000;
    int i, j;
    int tipo;
    int temCorrente;
    int temSalario;

    printf("Quantidade de clientes: ");
    scanf("%d", &quantidade);

    if (quantidade < 1 || quantidade > 100) {
        printf("Digite uma quantidade entre 1 e 100.\n");
        return 0;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nNome do cliente: ");
        scanf(" %39[^\n]", clientes[i].nome);

        clientes[i].fezEmprestimo = 0;
        temCorrente = 0;
        temSalario = 0;

        printf("Quantas contas deseja cadastrar? (1 a 3): ");
        scanf("%d", &quantidadeContas);

        while (quantidadeContas < 1 || quantidadeContas > 3) {
            printf("Digite 1, 2 ou 3: ");
            scanf("%d", &quantidadeContas);
        }

        for (j = 0; j < quantidadeContas; j++) {
            do {
                printf("\nTipo da conta:\n");
                printf("1 - Corrente\n");
                printf("2 - Salario\n");
                printf("3 - Poupanca\n");
                printf("Escolha: ");
                scanf("%d", &tipo);

                if (tipo < 1 || tipo > 3) {
                    printf("Tipo invalido.\n");
                } else if (tipo == 1 && temSalario == 1) {
                    printf("Esse cliente ja tem conta salario.\n");
                } else if (tipo == 2 && temCorrente == 1) {
                    printf("Esse cliente ja tem conta corrente.\n");
                }

            } while (tipo < 1 || tipo > 3 ||
                     (tipo == 1 && temSalario == 1) ||
                     (tipo == 2 && temCorrente == 1));

            contas[totalContas].idCliente = i;
            contas[totalContas].numeroConta = numeroConta;
            contas[totalContas].tipoConta = tipo;

            printf("Saldo inicial: R$ ");
            scanf("%f", &contas[totalContas].saldo);

            printf("Numero da conta: %04d-%02d\n", numeroConta, tipo);

            if (tipo == 1) {
                temCorrente = 1;
            }

            if (tipo == 2) {
                temSalario = 1;
            }

            numeroConta++;
            totalContas++;
        }
    }

    return quantidade;
}
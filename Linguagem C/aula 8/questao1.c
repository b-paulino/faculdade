#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    double preco;
} Produto;

void ordenar_numeros(int *vetor, int quantidade) {
    int i, j, auxiliar;
    for (i = 0; i < quantidade - 1; i++) {
        for (j = i + 1; j < quantidade; j++) {
            if (vetor[i] < vetor[j]) {
                auxiliar = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = auxiliar;
            }
        }
    }
}

void ordenar_produtos(Produto *produtos, int quantidade) {
    int i, j;
    Produto auxiliar;
    for (i = 0; i < quantidade - 1; i++) {
        for (j = i + 1; j < quantidade; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                auxiliar = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = auxiliar;
            }
        }
    }
}

int main(void) {
    int *numeros = malloc(12 * sizeof(int));
    int *distintos = malloc(12 * sizeof(int));
    int *ocorrencias = calloc(12, sizeof(int));
    int *pares = malloc(12 * sizeof(int));
    Produto *produtos = NULL;
    int i, j, posicao;
    int qtd_distintos = 0, qtd_pares = 0;
    int qtd_produtos = 0, cadastrados = 0;

    if (numeros == NULL || distintos == NULL ||
        ocorrencias == NULL || pares == NULL) {
        printf("Erro ao reservar memoria.\n");
        free(numeros);
        free(distintos);
        free(ocorrencias);
        free(pares);
        return 1;
    }

    for (i = 0; i < 12; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        posicao = -1;
        for (j = 0; j < qtd_distintos; j++) {
            if (numeros[i] == distintos[j]) {
                posicao = j;
            }
        }
        if (posicao == -1) {
            distintos[qtd_distintos] = numeros[i];
            ocorrencias[qtd_distintos] = 1;
            qtd_distintos++;
        } else {
            ocorrencias[posicao]++;
        }
    }

    for (i = 0; i < qtd_distintos; i++) {
        if (ocorrencias[i] % 2 == 0) {
            pares[qtd_pares] = distintos[i];
            qtd_pares++;
        } else if (distintos[i] > 0) {
            qtd_produtos += distintos[i];
        }
    }
    if (qtd_produtos > 0) {
        produtos = malloc((size_t) qtd_produtos * sizeof(Produto));
        if (produtos == NULL) {
            printf("Erro ao reservar memoria.\n");
            free(numeros);
            free(distintos);
            free(ocorrencias);
            free(pares);
            return 1;
        }
    }
    for (i = 0; i < qtd_distintos; i++) {
        if (ocorrencias[i] % 2 != 0 && distintos[i] > 0) {
            printf("\nCadastre %d produtos:\n", distintos[i]);
            for (j = 0; j < distintos[i]; j++) {
                printf("Nome do produto: ");
                scanf(" %99[^\n]", produtos[cadastrados].nome);
                do {
                    printf("Preco unitario: ");
                    scanf("%lf", &produtos[cadastrados].preco);
                } while (produtos[cadastrados].preco < 0);
                cadastrados++;
            }
        }
    }
    ordenar_numeros(pares, qtd_pares);
    ordenar_produtos(produtos, qtd_produtos);
    printf("\nNumeros informados:\n");
    for (i = 0; i < 12; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n\nOcorrencias:\n");
    for (i = 0; i < qtd_distintos; i++) {
        printf("%d aparece %d vez(es).\n", distintos[i], ocorrencias[i]);
    }
    printf("\nProdutos em ordem alfabetica:\n");
    for (i = 0; i < qtd_produtos; i++) {
        printf("%s - R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }
    printf("\nNumeros com quantidade par de ocorrencias:\n");
    for (i = 0; i < qtd_pares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");
    free(numeros);
    free(distintos);
    free(ocorrencias);
    free(pares);
    free(produtos);
    return 0;
}

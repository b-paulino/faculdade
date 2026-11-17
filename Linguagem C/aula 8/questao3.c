/* Veja no README.md a interpretacao adotada para esta questao. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
} Animal;

int primo(int numero) {
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

int main(void) {
    int *numeros = malloc(15 * sizeof(int));
    int *distintos = malloc(15 * sizeof(int));
    int *ocorrencias = calloc(15, sizeof(int));
    Animal *animais = NULL;
    int i, j, posicao;
    int qtd_distintos = 0;
    int qtd_animais = 0, cadastrados = 0;
    int quantidade, encontrou = 0;

    if (numeros == NULL || distintos == NULL || ocorrencias == NULL) {
        printf("Erro ao reservar memoria.\n");
        free(numeros);
        free(distintos);
        free(ocorrencias);
        return 1;
    }
    for (i = 0; i < 15; i++) {
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
    printf("\nNumeros repetidos:\n");
    for (i = 0; i < qtd_distintos; i++) {
        if (ocorrencias[i] > 1) {
            printf("%d: %d ocorrencias\n", distintos[i], ocorrencias[i]);
            if (primo(distintos[i]) && ocorrencias[i] % 2 != 0) {
                qtd_animais += distintos[i] * ocorrencias[i];
            }
        }
    }
    if (qtd_animais > 0) {
        animais = malloc((size_t) qtd_animais * sizeof(Animal));
        if (animais == NULL) {
            printf("Erro ao reservar memoria.\n");
            free(numeros);
            free(distintos);
            free(ocorrencias);
            return 1;
        }
    }
    for (i = 0; i < qtd_distintos; i++) {
        if (ocorrencias[i] > 1 && primo(distintos[i]) &&
            ocorrencias[i] % 2 != 0) {
            quantidade = distintos[i] * ocorrencias[i];
            printf("\nNumero %d: cadastre %d nomes de animais.\n",
                   distintos[i], quantidade);
            for (j = 0; j < quantidade; j++) {
                printf("Animal %d: ", cadastrados + 1);
                scanf(" %99[^\n]", animais[cadastrados].nome);
                cadastrados++;
            }
        }
    }
    printf("\nAnimais cadastrados pelas somas dos primos:\n");
    for (i = 0; i < qtd_animais; i++) {
        printf("%d. %s\n", i + 1, animais[i].nome);
    }
    printf("\nCorrespondencias pelas posicoes:\n");
    for (i = 0; i < 15; i++) {
        posicao = -1;
        for (j = 0; j < qtd_distintos; j++) {
            if (numeros[i] == distintos[j]) {
                posicao = j;
            }
        }
        if (ocorrencias[posicao] % 2 == 0) {
            encontrou = 1;
            printf("Numero %d, posicao %d: ", numeros[i], i + 1);
            if (i < qtd_animais) {
                printf("%s\n", animais[i].nome);
            } else {
                printf("Nao existe correspondencia.\n");
            }
        }
    }
    if (encontrou == 0) {
        printf("Nenhum numero com quantidade par de ocorrencias.\n");
    }
    free(numeros);
    free(distintos);
    free(ocorrencias);
    free(animais);
    return 0;
}

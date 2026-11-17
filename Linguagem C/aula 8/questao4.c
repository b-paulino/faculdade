#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
} Apostador;

long long soma_fibonacci(int quantidade) {
    long long anterior = 0, atual = 1;
    long long proximo, soma = 0;
    int i;
    for (i = 0; i < quantidade; i++) {
        soma += anterior;
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return soma;
}

int primo(long long numero) {
    long long i;
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
    Apostador *apostadores = malloc(5 * sizeof(Apostador));
    long long *resultados = malloc(5 * sizeof(long long));
    int *premiados = calloc(5, sizeof(int));
    int vencedores[3] = {-1, -1, -1};
    int i, quantidade, melhor;
    double media = 0;

    if (apostadores == NULL || resultados == NULL || premiados == NULL) {
        printf("Erro ao reservar memoria.\n");
        free(apostadores);
        free(resultados);
        free(premiados);
        return 1;
    }
    for (i = 0; i < 5; i++) {
        printf("\nNome do apostador %d: ", i + 1);
        scanf(" %99[^\n]", apostadores[i].nome);
        do {
            printf("Quantidade de termos, de 1 a 45: ");
            scanf("%d", &quantidade);
        } while (quantidade < 1 || quantidade > 45);
        resultados[i] = soma_fibonacci(quantidade);
        media += resultados[i];
    }
    media /= 5;
    melhor = -1;
    for (i = 0; i < 5; i++) {
        if (primo(resultados[i])) {
            if (melhor == -1 || resultados[i] > resultados[melhor]) {
                melhor = i;
            }
        }
    }
    vencedores[0] = melhor;
    if (melhor != -1) {
        premiados[melhor] = 1;
    }
    melhor = -1;
    for (i = 0; i < 5; i++) {
        if (premiados[i] == 0 && resultados[i] % 2 == 0) {
            if (melhor == -1 || resultados[i] > resultados[melhor]) {
                melhor = i;
            }
        }
    }
    vencedores[1] = melhor;
    if (melhor != -1) {
        premiados[melhor] = 1;
    }
    melhor = -1;
    for (i = 0; i < 5; i++) {
        if (premiados[i] == 0 && resultados[i] > media) {
            if (melhor == -1 || resultados[i] > resultados[melhor]) {
                melhor = i;
            }
        }
    }
    vencedores[2] = melhor;
    printf("\n");
    for (i = 0; i < 3; i++) {
        if (vencedores[i] != -1) {
            printf("%do lugar: %s\n", i + 1, apostadores[vencedores[i]].nome);
        } else {
            printf("%do lugar: sem vencedor.\n", i + 1);
        }
    }
    free(apostadores);
    free(resultados);
    free(premiados);
    return 0;
}

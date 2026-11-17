#include <stdio.h>
#include <stdlib.h>

int soma_fibonacci(int quantidade) {
    int i, anterior = 0, atual = 1, proximo, soma = 0;
    for (i = 0; i < quantidade; i++) {
        soma += anterior;
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return soma;
}

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
    char nomes[5][80];
    int *resultados = malloc(5 * sizeof(int));
    int premiados[5] = {0};
    int vencedores[3] = {-1, -1, -1};
    int i, lugar, quantidade, atende, melhor;
    double media = 0;
    if (resultados == NULL) {
        exit(1);
    }
    for (i = 0; i < 5; i++) {
        printf("Nome do apostador %d: ", i + 1);
        scanf(" %79[^\n]", nomes[i]);
        do {
            printf("Quantidade de termos (1 a 45): ");
            scanf("%d", &quantidade);
        } while (quantidade < 1 || quantidade > 45);
        resultados[i] = soma_fibonacci(quantidade);
        media += resultados[i];
    }
    media /= 5;
    /* Em cada rodada, procura o maior resultado que atende ao premio. */
    for (lugar = 0; lugar < 3; lugar++) {
        melhor = -1;
        for (i = 0; i < 5; i++) {
            if (lugar == 0) {
                atende = primo(resultados[i]);
            } else if (lugar == 1) {
                atende = resultados[i] % 2 == 0;
            } else {
                atende = resultados[i] > media;
            }
            if (premiados[i] == 0 && atende) {
                if (melhor == -1 || resultados[i] > resultados[melhor]) {
                    melhor = i;
                }
            }
        }
        vencedores[lugar] = melhor;
        if (melhor != -1) {
            premiados[melhor] = 1;
        }
    }
    printf("\n");
    for (lugar = 0; lugar < 3; lugar++) {
        if (vencedores[lugar] == -1) {
            printf("%do lugar: sem vencedor.\n", lugar + 1);
        } else {
            printf("%do lugar: %s\n", lugar + 1, nomes[vencedores[lugar]]);
        }
    }
    free(resultados);
    return 0;
}

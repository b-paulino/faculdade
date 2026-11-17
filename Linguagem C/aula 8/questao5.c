/* Veja no README.md a limitacao da regra de IDs do enunciado. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nome[100];
    int idade;
    long double id;
} Participante;

long double fatorial(int numero) {
    long double resultado = 1;
    int i;
    for (i = 2; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}

int id_repetido(Participante *participantes, int quantidade, long double id) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (participantes[i].id == id) {
            return 1;
        }
    }
    return 0;
}

double media_ponderada(double *valores, int quantidade) {
    double soma = 0, soma_pesos = 0;
    int i;
    for (i = 0; i < quantidade; i++) {
        soma += valores[i] * (i + 1);
        soma_pesos += i + 1;
    }
    return soma / soma_pesos;
}

void ordenar(Participante *participantes, double **matriz) {
    Participante auxiliar;
    double *linha_auxiliar;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (strcmp(participantes[i].nome, participantes[j].nome) > 0) {
                auxiliar = participantes[i];
                participantes[i] = participantes[j];
                participantes[j] = auxiliar;
                linha_auxiliar = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = linha_auxiliar;
            }
        }
    }
}

void liberar(Participante *participantes, double **matriz) {
    int i;
    if (matriz != NULL) {
        for (i = 0; i < 4; i++) {
            free(matriz[i]);
        }
    }
    free(matriz);
    free(participantes);
}

int main(void) {
    Participante *participantes = malloc(4 * sizeof(Participante));
    double **matriz = calloc(4, sizeof(double *));
    int quantidade, i, j;
    int qtd_lados = 0;
    double lados[2];
    double diagonal = 0, media, tolerancia;

    if (participantes == NULL || matriz == NULL) {
        printf("Erro ao reservar memoria.\n");
        liberar(participantes, matriz);
        return 1;
    }
    do {
        printf("Quantidade de valores por participante: ");
        scanf("%d", &quantidade);
    } while (quantidade <= 0);

    for (i = 0; i < 4; i++) {
        matriz[i] = malloc((size_t) quantidade * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Erro ao reservar memoria.\n");
            liberar(participantes, matriz);
            return 1;
        }
    }
    for (i = 0; i < 4; i++) {
        printf("\nNome do participante %d: ", i + 1);
        scanf(" %99[^\n]", participantes[i].nome);
        do {
            printf("Idade, de 0 a 20 nesta versao: ");
            scanf("%d", &participantes[i].idade);
        } while (participantes[i].idade < 0 || participantes[i].idade > 20);

        participantes[i].id = fatorial(participantes[i].idade) / 2;
        if (id_repetido(participantes, i, participantes[i].id)) {
            participantes[i].id = powl(
                fatorial(participantes[i].idade / 2), quantidade
            );
        }
        if (!isfinite(participantes[i].id)) {
            printf("O ID ultrapassou o limite numerico.\n");
            liberar(participantes, matriz);
            return 1;
        }
        if (id_repetido(participantes, i, participantes[i].id)) {
            printf("A formula alternativa tambem gerou um ID repetido.\n");
            printf("O enunciado precisa definir outra regra de desempate.\n");
            liberar(participantes, matriz);
            return 1;
        }
        for (j = 0; j < quantidade; j++) {
            printf("Valor %d: ", j + 1);
            scanf("%lf", &matriz[i][j]);
            if (matriz[i][j] >= 0 && qtd_lados < 2) {
                lados[qtd_lados] = matriz[i][j];
                qtd_lados++;
            }
        }
    }
    ordenar(participantes, matriz);
    if (qtd_lados == 2) {
        diagonal = hypot(lados[0], lados[1]);
    } else {
        printf("\nNao foi possivel calcular a diagonal.\n");
    }
    printf("\n---------- CLASSIFICACAO FINAL ----------\n");
    for (i = 0; i < 4; i++) {
        printf("%s: ", participantes[i].nome);
        if (qtd_lados < 2) {
            printf("sem classificacao, diagonal indisponivel.\n");
        } else {
            media = media_ponderada(matriz[i], quantidade);
            tolerancia = 0.000000001 *
                         fmax(1.0, fmax(fabs(media), fabs(diagonal)));
            if (fabs(media - diagonal) <= tolerancia) {
                printf("SOBRE A DIAGONAL\n");
            } else if (media > diagonal) {
                printf("ACIMA DA DIAGONAL\n");
            } else {
                printf("ABAIXO DA DIAGONAL\n");
            }
        }
    }
    liberar(participantes, matriz);
    return 0;
}

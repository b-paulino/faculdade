/* A regra incompleta dos IDs esta explicada no README. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double fatorial(int numero) {
    int i;
    double resultado = 1;
    for (i = 2; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}

int repetido(double *ids, int quantidade, double id) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (ids[i] == id) {
            return 1;
        }
    }
    return 0;
}

double media_ponderada(double *valores, int quantidade) {
    int i;
    double soma = 0, pesos = 0;
    for (i = 0; i < quantidade; i++) {
        soma += valores[i] * (i + 1);
        pesos += i + 1;
    }
    return soma / pesos;
}

int main(void) {
    char nomes[4][80], nome_auxiliar[80];
    double ids[4], id_auxiliar, lados[2], diagonal = 0, media;
    double **valores = malloc(4 * sizeof(double *));
    double *linha_auxiliar;
    int i, j, idade, quantidade, qtd_lados = 0;
    if (valores == NULL) {
        exit(1);
    }
    do {
        printf("Quantidade de valores por pessoa (1 a 20): ");
        scanf("%d", &quantidade);
    } while (quantidade < 1 || quantidade > 20);

    for (i = 0; i < 4; i++) {
        valores[i] = malloc(quantidade * sizeof(double));
        if (valores[i] == NULL) {
            exit(1);
        }
        printf("Nome do participante %d: ", i + 1);
        scanf(" %79[^\n]", nomes[i]);
        do {
            printf("Idade (0 a 20 nesta versao): ");
            scanf("%d", &idade);
        } while (idade < 0 || idade > 20);
        ids[i] = fatorial(idade) / 2;
        if (repetido(ids, i, ids[i])) {
            ids[i] = pow(fatorial(idade / 2), quantidade);
        }
        if (repetido(ids, i, ids[i])) {
            printf("ID ainda repetido: falta outra regra no enunciado.\n");
            exit(1);
        }
        for (j = 0; j < quantidade; j++) {
            printf("Valor %d: ", j + 1);
            scanf("%lf", &valores[i][j]);
            if (valores[i][j] >= 0 && qtd_lados < 2) {
                lados[qtd_lados] = valores[i][j];
                qtd_lados++;
            }
        }
    }
    /* Troca o nome, o ID e a linha de valores juntos. */
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                strcpy(nome_auxiliar, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], nome_auxiliar);
                id_auxiliar = ids[i];
                ids[i] = ids[j];
                ids[j] = id_auxiliar;
                linha_auxiliar = valores[i];
                valores[i] = valores[j];
                valores[j] = linha_auxiliar;
            }
        }
    }
    if (qtd_lados == 2) {
        diagonal = sqrt(lados[0] * lados[0] + lados[1] * lados[1]);
    } else {
        printf("\nNao foi possivel calcular a diagonal.\n");
    }
    printf("\nCLASSIFICACAO FINAL\n");
    for (i = 0; i < 4; i++) {
        printf("%s: ", nomes[i]);
        media = media_ponderada(valores[i], quantidade);
        if (qtd_lados < 2) {
            printf("sem classificacao.\n");
        } else if (fabs(media - diagonal) < 0.000001) {
            printf("SOBRE A DIAGONAL\n");
        } else if (media > diagonal) {
            printf("ACIMA DA DIAGONAL\n");
        } else {
            printf("ABAIXO DA DIAGONAL\n");
        }
        free(valores[i]);
    }
    free(valores);
    return 0;
}

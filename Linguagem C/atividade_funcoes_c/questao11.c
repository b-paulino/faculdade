#include <stdio.h>

float calcularMediaTurma(float notas[]) {
    float soma = 0;
    int i;

    for (i = 0; i < 10; i++) {
        soma = soma + notas[i];
    }

    return soma / 10;
}

float encontrarMaiorNota(float notas[]) {
    float maior = notas[0];
    int i;

    for (i = 1; i < 10; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }

    return maior;
}

int contarAprovados(float notas[]) {
    int i, aprovados = 0;

    for (i = 0; i < 10; i++) {
        if (notas[i] >= 7.0) {
            aprovados++;
        }
    }

    return aprovados;
}

void exibirResultados(float media, float maiorNota, int aprovados) {
    printf("\nMedia da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maiorNota);
    printf("Quantidade de aprovados: %d\n", aprovados);
}

int main() {
    float notas[10], media, maiorNota;
    int i, aprovados;

    for (i = 0; i < 10; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    media = calcularMediaTurma(notas);
    maiorNota = encontrarMaiorNota(notas);
    aprovados = contarAprovados(notas);

    exibirResultados(media, maiorNota, aprovados);

    return 0;
}

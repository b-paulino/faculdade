#include <stdio.h>

float calcularTotal(float vendas[]) {
    float total = 0;
    int i;

    for (i = 0; i < 5; i++) {
        total = total + vendas[i];
    }

    return total;
}

float calcularMedia(float total, int quantidadeDias) {
    return total / quantidadeDias;
}

int contarVendasAcimaDaMedia(float vendas[], float media) {
    int i, quantidade = 0;

    for (i = 0; i < 5; i++) {
        if (vendas[i] > media) {
            quantidade++;
        }
    }

    return quantidade;
}

int main() {
    float vendas[5], total, media;
    int i, diasAcimaDaMedia;

    for (i = 0; i < 5; i++) {
        printf("Digite a venda do dia %d: R$ ", i + 1);
        scanf("%f", &vendas[i]);
    }

    total = calcularTotal(vendas);
    media = calcularMedia(total, 5);
    diasAcimaDaMedia = contarVendasAcimaDaMedia(vendas, media);

    printf("\nTotal vendido: R$ %.2f\n", total);
    printf("Media diaria: R$ %.2f\n", media);
    printf("Dias com vendas acima da media: %d\n", diasAcimaDaMedia);

    return 0;
}

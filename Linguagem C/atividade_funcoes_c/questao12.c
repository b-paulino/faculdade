#include <stdio.h>

int calcularTotalEstoque(int estoque[]) {
    int i, total = 0;

    for (i = 0; i < 8; i++) {
        total = total + estoque[i];
    }

    return total;
}

int contarEstoqueBaixo(int estoque[]) {
    int i, quantidade = 0;

    for (i = 0; i < 8; i++) {
        if (estoque[i] < 5) {
            quantidade++;
        }
    }

    return quantidade;
}

int buscarProduto(int estoque[], int codigo) {
    // Os codigos vao de 1 a 8, e os indices do vetor vao de 0 a 7
    if (codigo >= 1 && codigo <= 8) {
        int posicao = codigo - 1;
        if (estoque[posicao] >= 0) {
            return posicao;
        }
    }

    return -1;
}

int main() {
    int estoque[8], i, codigo, posicao;
    int total, produtosComEstoqueBaixo;

    for (i = 0; i < 8; i++) {
        printf("Quantidade do produto %d: ", i + 1);
        scanf("%d", &estoque[i]);
    }

    total = calcularTotalEstoque(estoque);
    produtosComEstoqueBaixo = contarEstoqueBaixo(estoque);

    printf("\nTotal de unidades em estoque: %d\n", total);
    printf("Produtos com menos de 5 unidades: %d\n", produtosComEstoqueBaixo);

    printf("\nDigite o codigo de um produto (1 a 8): ");
    scanf("%d", &codigo);

    posicao = buscarProduto(estoque, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado.\n");
    } else {
        printf("Produto encontrado no indice %d do vetor.\n", posicao);
        printf("Quantidade disponivel: %d\n", estoque[posicao]);
    }

    return 0;
}

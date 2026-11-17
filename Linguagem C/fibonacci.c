#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int soma_fibonacci(int numero) {
    int i, soma = 0;

    if (numero > 0) {
        for (i = 0; i < numero; i++) {
            soma = soma + fibonacci(i);
        }
    }

    return soma;
}

int num_primo(int numero) {
    int i, divisores = 0;

    if (numero < 2) {
        return 0;
    }

    for (i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int num_par(int numero) {
    if (numero % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char nomes[5][30];
    int somas[5];
    int numero, i;
    int primeiro = -1, segundo = -1;

    for (i = 0; i < 5; i++) {
        printf("\nNome do apostador %d: ", i + 1);
        scanf("%29s", nomes[i]);

        printf("Digite um numero de 1 a 30: ");
        scanf("%d", &numero);

        somas[i] = soma_fibonacci(numero);
    }

    for (i = 0; i < 5; i++) {
        if (num_primo(somas[i]) == 1) {
            if (primeiro == -1 || somas[i] > somas[primeiro]) {
                primeiro = i;
            }
        }
    }

    for (i = 0; i < 5; i++) {
        if (num_par(somas[i]) == 1 && i != primeiro) {
            if (segundo == -1 || somas[i] > somas[segundo]) {
                segundo = i;
            }
        }
    }

    printf("\n===== RESULTADO =====\n");

    for (i = 0; i < 5; i++) {
        printf("\nNome: %s", nomes[i]);
        printf("\nSoma Fibonacci: %d", somas[i]);

        if (i == primeiro) {
            printf("\nClassificacao: 1 lugar\n");
        }
        else if (i == segundo) {
            printf("\nClassificacao: 2 lugar\n");
        }
        else {
            printf("\nClassificacao: Nao classificado\n");
        }
    }

    return 0;
}

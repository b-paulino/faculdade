#include <stdio.h>

float celsiusParaFahrenheit(float C) {
    return (9 * C) / 5 + 32;
}

int main() {
    float C, fahrenheit;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &C);

    fahrenheit = celsiusParaFahrenheit(C);
    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}

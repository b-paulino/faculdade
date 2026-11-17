# 3) Escreva um programa que leia diversos números inteiros
# positivos e exiba o dobro de cada um. A leitura deve ser
# interrompida quando for digitado um número negativo.
while True: 
    numero = int(input("Digite um número: "))

    if (numero < 0):
        print("Número negativo, programa encerrado")
        break
    
    print(f"O dobro de {numero} é {numero * 2}")

# Escreva um programa que leia um número inteiro positivo (n > 1)
# e imprima os seus divisores
numero = int(input("Digite um número inteiro para ver seus divisores: "))
divisores = []

if (numero > 1):
    for i in range(1, numero + 1):
        if (numero % i == 0):
            divisores.append(i)
    print(divisores)

print("Número negativo. Por favor informar um número positivo.")

# Crie um programa que:
# • Leia 8 números inteiros e os armazene em uma lista.
# • Mostre:
# • O maior valor
# • O menor valor
# • A quantidade de números pare
numeros = []
pares = 0

for _ in range(10):
    numero = int(input("Digite um número: "))
    numeros.append(numero)

    if numero % 2 == 0:
        pares += 1

print(f"Maior valor: {max(numeros)}")
print(f"Menor valor: {min(numeros)}")
print(f"Quantidade de números pares: {pares}")

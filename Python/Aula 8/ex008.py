# Crie um programa que: leia 12 números inteiros e armazene-os em uma lista, exiba os números em ordem
# crescente, exiba os números em ordem decrescente, informe quantos números são pares e quantos são
# ímpares
numeros = []
pares = 0
impares = 0

for _ in range(12):
    numero = int(input("Digite um número: "))
    numeros.append(numero)

    if numero % 2 == 0:
        pares += 1
    else:
        impares += 1

crescente = sorted(numeros)
decrescente = sorted(numeros, reverse=True)

print(f"Ordem Crescente: {crescente}")
print(f"Ordem Decrescente: {decrescente}")
print(f"Quantidade pares: {pares}")
print(f"Quantidade impares {impares}")

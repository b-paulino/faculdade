# Desenvolva um programa que: leia 10 números inteiros e os armazene em uma lista, solicite ao usuário um
# número para remoção, remova todas as ocorrências desse número da lista, exiba a lista atualizada. Caso o
# número não exista na lista, informe ao usuário.
numeros = []

for _ in range(10):
    numero = int(input("Digite um número para adicionar à lista: "))
    numeros.append(numero)

print(f"Lista: {numeros}")

remover = int(input("Digite o número que deseja remover da lista: "))

if (remover in numeros):
    while (remover  in numeros):
        numeros.remove(remover)
    print(f"O número {remover} foi removido.")
    print(f"Lista atualizada: {numeros}")
else:
    print("Número não encontrado.")


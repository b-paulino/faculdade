# Receba 15 números inteiros e armazene-os em uma lista. Depois: crie uma lista apenas com números
# pares, crie outra lista apenas com números ímpares, exiba as duas listas.
numeros = []
impares = []
pares = []

for i in range(15):
    numero = int(input("Digite um número: "))
    numeros.append(numero)

    if (numero % 2 == 0):
        pares.append(numero)
    else:
        impares.append(numero)
    
print(f"Pares: {pares}")
print(f"Ímpares: {impares}")

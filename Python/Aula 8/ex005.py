# Leia 20 números inteiros e armazene-os em uma lista. Depois: conte quantos números são positivos
# conte quantos são negativos, conte quantos são iguais a zero.
numeros = []
positivos = 0
negativos = 0
zeros = 0

for _ in range(20):
    numero = int(input("Digite um número para adicionar à lista: "))
    numeros.append(numero)

    if (numero > 0):
        positivos += 1
    elif (numero < 0):
        negativos += 1
    else:
        zeros += 1

print(f"Números: {numeros}")
print(f"Positivos: {positivos}")
print(f"Negativos: {negativos}")
print(f"Zeros: {zeros}")

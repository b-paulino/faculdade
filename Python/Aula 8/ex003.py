# Leia 8 números inteiros e armazene-os em uma lista. Em seguida: solicite um número ao usuário,
# informe se o número está ou não presente na lista.
numeros = []

for i in range(8):
    numero = int(input("Digite um número para adicionar à lista: "))
    numeros.append(numero)

busca = int(input("Digite o número que deseja realizar a busca: "))

if busca in numeros:
    print("O número está na lista.")
else:
    print("O número não está na lista.")

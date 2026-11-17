# Leia 10 números inteiros e armazene-os em uma lista. Ao final: 
# mostre todos os valores, informe o maior valor, informe o menor valor.
lista = []

for i in range(10):
    numero = int(input("Digite o número para adicionar na lista: "))
    lista.append(numero)

print(f"Lista: {lista}.")
print(f"Maior número: {max(lista)}.")
print(f"Menor número: {min(lista)}.")

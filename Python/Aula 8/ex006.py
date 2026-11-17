# Crie duas listas com 5 números cada. Depois: informe quais valores aparecem nas duas listas, informe
# quais valores são exclusivos de cada lista.
lista_1 = []
lista_2 = []
comuns = []
exclusivos_1 = []
exclusivos_2 = []

for _ in range(5):
    numero = int(input("Digite o número para adicionar na primeira lista: "))
    lista_1.append(numero)

    numero = int(input("Digite o número para adicionar na segunda lista: "))
    lista_2.append(numero)

for numero in lista_1:
    if numero in lista_2:
        comuns.append(numero)
    else:
        exclusivos_1.append(numero)

for numero in lista_2:
    if numero not in lista_1:
        exclusivos_2.append(numero)

print(f"Comuns em ambas listas: {comuns}")
print(f"Exclusivos da primeira lista: {exclusivos_1}")
print(f"Exclusivos da segunda lista: {exclusivos_2}")

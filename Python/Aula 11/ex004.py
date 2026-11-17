# 4. Crie uma matriz 3x3 preenchida pelo usuário.
# • Ao final, exiba:
# • A soma de todos os elementos da matriz.
# • A soma dos elementos da diagonal principal.
matriz = []

for i in range(3):
    linha = []

    for j in range(3):
        numero = int(input(f"Digite o valor [{i}][{j}]: "))
        linha.append(numero)
    
    matriz.append(linha)

soma = 0 

for i in range(3):
    for j in range(3):
        soma += matriz[i][j]

diagonal = 0 

for i in range(3):
    for j in range(3):
        if i == j:
            diagonal += matriz[i][j]

print(f"Soma de todos elementos: {soma}")
print(f"Soma da diagonal: {diagonal}")

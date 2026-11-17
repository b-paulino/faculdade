# Peça várias notas ao usuário (encerra quando digitar -1) 
# e calcule a média das notas válidas.

nota = 0
soma = 0
quantidade_notas = 0

while (nota != -1):
    nota = float(input("Informe o valor da nota: "))

    if (nota == -1):
        break

    if (nota != -1):
        soma += nota
        quantidade_notas += 1

media = soma / quantidade_notas

print(f"A media das notas é {media}.")

# Considere um arquivo chamado notas.txt contendo uma nota por linha.
# Faça um programa que:
# • Leia todas as notas.
# • Armazene-as em uma lista.
# • Exiba:
# • Quantidade de notas
# • Maior nota
# • Menor nota
# • Média das notas
notas = []

with open("notas.txt", "r") as arquivo:
    for linha in arquivo:
        notas.append(float(linha))

print(f"Quantidade de notas: {len(notas)}")
print(f"Maior nota: {max(notas)}")
print(f"Menor nota: {min(notas)}")
print(f"Média: {sum(notas) / len(notas)}")
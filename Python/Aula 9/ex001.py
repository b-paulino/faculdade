# Crie um programa que receba uma palavra e mostre quantas vogais existem nela.
palavra = input("Digite uma palavra: ").lower()
vogais = 0

for letra in palavra:
    if letra in "aeiou":
        vogais += 1

print(vogais)

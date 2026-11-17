# Faça um programa que verifique se uma palavra é um palíndromo (ex.: “arara”).
palavra = input("Digite uma palavra: ").lower()

if palavra == palavra[::-1]:
    print("É um palíndromo.")
else:
    print("Não é um palíndromo.")

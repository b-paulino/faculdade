# Receba uma frase e substitua todas as ocorrências de uma palavra específica por outra.
frase = input("Digite uma frase: ")
palavra_antiga = input("Qual palavra deseja substituir? ")
palavra_nova = input("Qual será a nova palavra? ")

frase = frase.replace(palavra_antiga, palavra_nova)

print(frase)

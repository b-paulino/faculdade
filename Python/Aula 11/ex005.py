# 5. Faça um programa que solicite ao usuário 5 nomes e os grave em um
# arquivo chamado nomes.txt, um nome por linha.
with open("nomes.txt", "w") as arquivo:
    for _ in range(5):
        nome = input("Digite um nome: ")
        arquivo.write(nome + "\n")
    
print("Nomes gravados com sucesso!")

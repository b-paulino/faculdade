# Cadastre: nome, preço, quantidade em estoque de 5 produtos utilizando listas. Depois: mostre os
# produtos com estoque menor que 10, informe o produto mais caro.
nome = []
preco = []
quantidade = []
estoque_baixo = []

for i in range(5):
    nome_produto = input("Digite o nome do produto: ")
    nome.append(nome_produto)
    preco_produto = float(input("Digite o valor do produto: R$"))
    preco.append(preco_produto)
    quantidade_produto = int(input("Digite a quantidade em estoque: "))
    quantidade.append(quantidade_produto)

    if quantidade_produto < 10:
        estoque_baixo.append(nome_produto)

mais_caro = preco[0]
indice = 0

for i in range(5):
    if preco[i] > mais_caro:
        mais_caro = preco[i]
        indice = i

print(f"Produto mais caro: {nome[indice]}")
print(f"Preço: R$ {preco[indice]}")
print(f"Produtos com estoque menor que 10: {estoque_baixo}")

# O computador escolhe um número fixo. 
# O usuário continua tentando adivinhar até acertar. Ao final, informe:
# quantas tentativas ele fez;
# quantos palpites foram maiores que o número correto;
# quantos foram menores.

numero = 23
tentativa = 0
palpite_maior = 0
palpite_menor = 0

while True:
    palpite = int(input("Qual é o número escondido? "))
    tentativa += 1

    if (palpite == numero):
        print(f"Parabéns, você acertou o numero {numero} em {tentativa} tentativas!")
        print(f"Tentativas maiores que {numero}: {palpite_maior}.")
        print(f"Tentativas menores que {numero}: {palpite_menor}.")
        break
    elif (palpite > numero):
        palpite_maior += 1
    else:
        palpite_menor += 1

# Defina um número fixo no código. 
# Peça ao usuário para adivinhar até acertar. 
# Informe se o palpite é maior ou menor que o número correto.

numero = 5

while True:
    palpite = int(input("Tente adivinhar o número: "))

    if (palpite == numero):
        print("Parabéns, você acertou!")
        break
    elif (palpite < numero):
        print("O número é maior.")
    else:
        print("O número é menor.")

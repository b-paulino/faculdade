# 5) Escreva um programa que repita as seguintes etapas até que o
# usuário digite a palavra "nao":
# i. Leia a distância percorrida por um atleta (em Km);
# ii. Leia o tempo gasto para percorrer essa distância (em horas);
# iii. Calcule e exiba a velocidade média do atleta 
# (velocidade = distância / tempo);
# iv. Pergunte ao usuário se deseja continuar utilizando o programa
# (respostas possíveis: "sim" ou "nao").

while True:
    distancia = float(input("Qual foi a distancia percorrida em km? "))
    tempo = float(input("Quantas horas(H) levou? "))
    velocidade = distancia / tempo

    print(f"A velocidade média do atleta foi de {velocidade}km/h.")

    continuidade = input("Deseja continuar utilizando o programa? ").lowe()

    if (continuidade == "nao"):
        break

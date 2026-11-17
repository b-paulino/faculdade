# 4) Cada espectador de um cinema respondeu a um questionário com
# a seguinte pergunta: Qual a sua opinião sobre o filme?
# As opções de resposta foram: 3 – Ótimo, 2 – Bom e 1 – Regular
# Escreva um programa que leia as respostas de 15 espectadores e
# informe:
# A quantidade de pessoas que responderam "Ótimo";
# A quantidade de pessoas que responderam "Bom";
# A quantidade de pessoas que responderam "Regular".
otimo = 0
bom = 0
regular = 0

for i in range(15):
    opiniao = int(input("Qual a sua opnião sobre o filme? 3 - Ótimo 2 - Bom 1 - Regular "))
    
    if (opiniao == 3):
        otimo += 1
    elif (opiniao == 2):
        bom += 1
    elif (opiniao == 1):
        regular += 1
    else:
        print("Opção inválida!")

print("Resultado da pesquisa:\n")
print(f"Ótimo: {otimo} \nBom: {bom} \nRegular: {regular}")

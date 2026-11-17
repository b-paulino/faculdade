# Desenvolva um programa que solicite ao usuário a digitação de uma nota entre 0 
# e 10. Caso o valor informado esteja fora desse intervalo, o programa deve exibir
# uma mensagem de erro e solicitar novamente a entrada, repetindo o processo até
# que um valor válido seja informado

nota = float(input("Digite a nota: "))

while (nota < 0) or (nota > 10):
    print("Nota inválida!")
    print("Digite uma nota entra 0 e 10.")
    nota = float(input("Digite a nota novamente: "))

print("Nota: ", nota)

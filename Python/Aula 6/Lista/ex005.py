#Peça números ao usuário continuamente e informe se cada número é par ou ímpar. O programa só
#deve parar quando o usuário digitar 0

status = True

while (status == True):
    numero = int(input("Digite um número para saber se ele é impar ou par: "))
    if numero == 0:
        status = False
    elif (numero % 2 == 0):
        print(f"O numero {numero} é PAR")
    else:
        print(f"O numero {numero} é IMPAR")

print("FIM DO PROGRAMA")

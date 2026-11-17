numeros_positivos = 0
OK = True

while OK:
    numero = int(input("Digite um número positivo: "))
    if (numero > 0):
        numeros_positivos = numeros_positivos + 1
    else:
        OK = False

print("Quantidade de números positivos fornecidos: ", numeros_positivos)

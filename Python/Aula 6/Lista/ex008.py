# Peça números ao usuário até que ele digite 0. 
# Ao final, informe quantos números positivos e quantos
# negativos foram digitados.

positivo = 0
negativo = 0

while True:
    numero = int(input("Digite um número: "))

    if (numero == 0):
        break

    if (numero > 0):
        positivo += 1
    else:
        negativo += 1

print(f"Números positivos: {positivo}. \nNúmeros negativos: {negativo}.")

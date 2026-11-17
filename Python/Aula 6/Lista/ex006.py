maior = 0
numero = 1

while (numero != 0):
    numero = int(input("Informe um número: "))

    if (numero == 0):
        break

    if (numero > maior):
        maior = numero

print(f"O maior número digitado foi {maior}.")

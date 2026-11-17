numero = int(input("Informe o número que deseja calcular o fatorial: "))
fatorial = 1

while (numero > 0):
    fatorial = fatorial * numero
    numero = numero - 1

print(f"O fatorial é {fatorial}.")

#Peça números ao usuário e some-os. O programa deve parar quando o usuário digitar um número
#negativo. Ao final, mostre a soma total.

positivo = True
soma = 0
numero = int(input("Digite um número: "))

while (positivo == True):
    if (numero < 0):
        positivo = False
    else:
        numero = int(input("Digite outro número: "))
        soma = soma + numero

print("Programa encerrado.")
print(f"A soma total dos números é {soma}")

# Faça um programa que leia a nota de um aluno (0 a 10) e informe sua
# situação:
# • Aprovado: nota maior ou igual a 7
# • Recuperação: nota entre 5 e 6,9
# • Reprovado: nota menor que 5
nota = float(input("Digite a nota do aluno (0 a 10): "))

if nota >= 7:
    print("Aprovado")
elif nota >= 5:
    print("Recuperação")
else:
    print("Reprovado")

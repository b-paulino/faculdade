#Peça ao usuário para digitar uma senha. Continue solicitando até que ele acerte a senha correta
#(defina uma senha fixa no código).

senha = 1504
info_senha = int(input("Informe a senha: "))

while (info_senha != senha):
    info_senha = int(input("Senha incorreta, informe a senha novamente: "))

print("Senha correta!")

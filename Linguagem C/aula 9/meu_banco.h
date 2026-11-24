typedef struct {
    int idCliente;
    int numeroConta;
    int tipoConta;
    float saldo;
    char historico[200];
} Conta;

typedef struct {
    char nome[40];
    int fezEmprestimo;
} Cliente;

void mostrarMenu(void);

int cadastrarClientes(Cliente clientes[], Conta contas[]);
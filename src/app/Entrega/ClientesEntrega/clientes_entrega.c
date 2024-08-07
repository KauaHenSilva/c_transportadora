#include <clientes_entrega.h>
#include <print_struct.h>
#include <utils.h>
#include <print_struct.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int idCliente = 1;
static int idProduto = 1;

void cadastrarCliente(ClienteEnvio **cliente)
{
    char *nome;
    char *endereco;
    char *cpf;

    get_string(&nome, "Digite o nome do cliente: ");
    get_string(&endereco, "Digite o endereço do cliente: ");
    get_string(&cpf, "Digite o CPF do cliente: ");

    while (validarCPF(*cliente, cpf))
    {
        printf("CPF já cadastrado.\n");
        get_string(&cpf, "Digite o CPF do cliente: ");
    }

    ClienteEnvio *novoCliente = (ClienteEnvio *)malloc(sizeof(ClienteEnvio));
    if (!novoCliente)
        perror("Erro ao alocar memória para o cliente.");

    novoCliente->idCliente = idCliente++;
    novoCliente->nome = nome;
    novoCliente->endereco = endereco;
    novoCliente->cpf = cpf;
    novoCliente->prox = NULL;

    if (*cliente == NULL)
    {
        *cliente = novoCliente;
        printf("Cliente cadastrado com sucesso.\n");
        return;
    }

    ClienteEnvio *atual = *cliente;
    while (atual->prox != NULL)
        atual = atual->prox;
    atual->prox = novoCliente;

    printf("Cliente cadastrado com sucesso.\n");
}

int listarClientes(ClienteEnvio *cliente)
{
    if (cliente == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return 1;
    }

    printlistarClientes(cliente);
    return 0;
}

void editarCliente(ClienteEnvio *cliente)
{
    if (cliente == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    int idParaEditar;
    get_int(&idParaEditar, "Digite o ID do cliente que deseja editar: ", 1, idCliente - 1);

    ClienteEnvio *atual = retornarCliente(cliente, idParaEditar);
    if (atual == NULL)
    {
        printf("Cliente com ID %d não encontrado.\n", idParaEditar);
        return;
    }

    int confimao;

    get_int(&confimao, "Deseja editar o nome? 1 - Sim | 0 - Não: ", 0, 1);
    if (confimao)
        get_string(&atual->nome, "Digite o novo nome do cliente: ");

    get_int(&confimao, "Deseja editar o endereço? 1 - Sim | 0 - Não: ", 0, 1);
    if (confimao)
        get_string(&atual->endereco, "Digite o novo endereço do cliente: ");

    printf("Não é possível editar o CPF.\n");
    printf("Cliente com ID %d editado com sucesso.\n", idParaEditar);
}

void excluirCliente(ClienteEnvio **cliente)
{
    if (*cliente == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    int idParaExcluir;
    printf("Digite o ID do cliente que deseja excluir: ");
    get_int(&idParaExcluir, "Digite o ID do cliente que deseja excluir: ", 1, idCliente - 1);

    ClienteEnvio *atual = *cliente;
    ClienteEnvio *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->idCliente == idParaExcluir)
        {
            if (anterior == NULL)
                *cliente = atual->prox;
            else
                anterior->prox = atual->prox;

            free(atual->nome);
            free(atual->endereco);
            free(atual);

            printf("Cliente com ID %d excluído com sucesso.\n", idParaExcluir);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Cliente com ID %d não encontrado.\n", idParaExcluir);
}

int validarCPF(ClienteEnvio *cliente, char *cpf)
{
    ClienteEnvio *atual = cliente;
    while (atual != NULL)
    {
        if (strcmp(atual->cpf, cpf) == 0)
            return 1;
        atual = atual->prox;
    }

    return 0;
}

void freeClientes(ClienteEnvio **cliente)
{
    ClienteEnvio *atual = *cliente;
    ClienteEnvio *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual->nome);
        free(atual->endereco);
        free(atual->cpf);
        free(atual);
        atual = proximo;
    }

    *cliente = NULL;
}

ClienteEnvio *retornarCliente(ClienteEnvio *cliente, int id)
{
    ClienteEnvio *atual = cliente;

    while (atual != NULL)
    {
        if (atual->idCliente == id)
            return atual;
        atual = atual->prox;
    }

    return NULL;
}

Produto *cadrastrarProduto(ClienteEnvio *cliente)
{
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (!novoProduto)
        perror("Erro ao alocar memória para o produto.");

    printf("Selecione o cliente para associar o produto:\n");
    if (listarClientes(cliente))
    {
        printf("Não é possível cadastrar um produto sem um cliente.\n");
        return NULL;
    }

    int idCliente;
    get_int(&idCliente, "Digite o ID do cliente: ", 1, idCliente - 1);

    ClienteEnvio *clienteSelecionado = retornarCliente(cliente, idCliente);
    if (clienteSelecionado == NULL)
    {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        return NULL;
    }

    get_string(&novoProduto->nome, "Digite o nome do produto: ");
    novoProduto->id_produto = idProduto++;
    novoProduto->cliente = clienteSelecionado;
    novoProduto->prox = NULL;

    return novoProduto;
}

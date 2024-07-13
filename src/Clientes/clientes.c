#include <clientes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Clientes *clientes = NULL;

void hello_word_clientes()
{
  printf("Hello, World! Clientes\n");
}

void cadastrarCliente(Clientes **cliente) {
    // Declarando variáveis para armazenar os dados do cliente
    int idCliente;
    char nome[100];
    char endereco[200];

    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove nova linha
    printf("Digite o endereço do cliente: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0'; // Remove nova linha

    // Solicitando os dados do cliente
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);
    getchar(); // Limpando o buffer 



    // Alocando memória para o novo cliente
    Clientes *novoCliente = (Clientes *)malloc(sizeof(Clientes));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Preenchendo os dados do cliente
    novoCliente->idCliente = idCliente;
    novoCliente->nome = strdup(nome); // Alocando a memória e copiando o nome do cliente
    novoCliente->endereco = strdup(endereco); // Alocando a memória e copiando o endereço
    novoCliente->prox = NULL;

    // Verificando se a lista está vazia
    if (*cliente == NULL) {
        *cliente = novoCliente;
    } else {
        // Inserindo o novo cliente no final da lista
        Clientes *atual = *cliente;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoCliente;
    }

    printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes(Clientes *cliente){
    Clientes *atual = cliente;
    while (atual != NULL) {
        printf("\n==============LISTA DE CLIENTES CADASTRADOS============================\n");
        printf("Nome: %s\nID: %d\nEndereço: %s\n", atual->nome, atual->idCliente, atual->endereco);
        atual = atual->prox;
        printf("=========================================================================");
    }
}


   void buscarCliente(Clientes *cliente) {
    int id_Busca;
    printf("\nDigite o ID do cliente que deseja buscar: ");
    scanf("%d", &id_Busca);

    Clientes *atual = cliente;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->idCliente == id_Busca) {
            printf("\n=================== DADOS DO CLIENTE ===================\n");
            printf("Nome: %s\n", atual->nome);
            printf("ID: %d\n", atual->idCliente);
            printf("Endereço: %s\n", atual->endereco);
            printf("========================================================\n");
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", id_Busca);
    }
}


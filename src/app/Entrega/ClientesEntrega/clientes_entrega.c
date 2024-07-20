#include <clientes_entrega.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cadastrarCliente(ClienteEnvio **cliente) {
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
    ClienteEnvio *novoCliente = (ClienteEnvio *)malloc(sizeof(ClienteEnvio));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Preenchendo os dados do cliente
    novoCliente->idCliente = idCliente;
    novoCliente->prox = NULL;

    novoCliente->nome = strdup(nome); // Alocando a memória e copiando o nome
    novoCliente->endereco = strdup(endereco); // Alocando a memória e copiando o endereço

    
    // Verificando se a lista está vazia
    if (*cliente == NULL) {
        *cliente = novoCliente;
    } else {
        // Inserindo o novo cliente no final da lista
        ClienteEnvio *atual = *cliente;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoCliente;
    }

    printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes(ClienteEnvio *cliente){
    ClienteEnvio *atual = cliente;
    while (atual != NULL) {
        printf("\n==============LISTA DE CLIENTES CADASTRADOS============================\n");
        printf("Nome: %s\nID: %d\nEndereço: %s\n", atual->nome, atual->idCliente, atual->endereco);
        atual = atual->prox;
        printf("=========================================================================");
    }
}


   void buscarCliente(ClienteEnvio *cliente) {
    int id_Busca;
    printf("\nDigite o ID do cliente que deseja buscar: ");
    scanf("%d", &id_Busca);

    ClienteEnvio *atual = cliente;
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

void editarCliente(ClienteEnvio *cliente){
    int idParaEditar;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &idParaEditar);

    ClienteEnvio *atual = cliente;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->idCliente == idParaEditar) {
            printf("\n=================== DADOS ATUAIS DO CLIENTE ===================\n");
            printf("Nome atual: %s\n", atual->nome);
            printf("Endereço atual: %s\n", atual->endereco);
            printf("==============================================================\n");

            printf("Digite o novo nome do cliente: ");
            scanf(" %[^\n]s", atual->nome);  // Lê o novo nome

            printf("Digite o novo endereço do cliente: ");
            scanf(" %[^\n]s", atual->endereco);  // Lê o novo endereço

            printf("Cliente editado com sucesso!\n");

            printf("\n=================== NOVOS DADOS ATUALIZADOS ===================\n");
            printf("Nome: %s\n", atual->nome);
            printf("Endereço: %s\n", atual->endereco);
            printf("==============================================================\n");


            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", idParaEditar);
    }
}

void excluirCliente(ClienteEnvio **cliente){
    int idParaExcluir;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &idParaExcluir);

    ClienteEnvio *atual = *cliente;
    ClienteEnvio *anterior = NULL;

    while (atual != NULL) {
        if (atual->idCliente == idParaExcluir) {
            if (anterior == NULL) {
                *cliente = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

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
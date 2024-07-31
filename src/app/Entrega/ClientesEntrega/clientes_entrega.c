#include <clientes_entrega.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dentro de Cliente Envio, temos um ponteiro de produtos, que é uma lista de produtos.
// Defina a função de cadastro de produtos. e a função de listar produtos. logo após cadastre os produtos no cliente.

void cadastrarProduto(Produto **produtos) {
    char nomeProduto[100];
    float preco;
    int quantidade;

    printf("Digite o nome do produto: ");
    fgets(nomeProduto, sizeof(nomeProduto), stdin);
    nomeProduto[strcspn(nomeProduto, "\n")] = '\0'; // Remove nova linha

    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);
    getchar(); // Limpar o buffer

    // Alocando memória para o novo produto
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memória para o produto.\n");
        return;
    }

    // Preenchendo os dados do produto
    novoProduto->nomeProduto = strdup(nomeProduto); // Alocando memória e copiando o nome do produto
    novoProduto->preco = preco;
    novoProduto->quantidade = quantidade;
    novoProduto->proxProduto = NULL;

    // Inserindo o novo produto no final da lista de produtos
    if (*produtos == NULL) {
        *produtos = novoProduto;
    } else {
        Produto *atual = *produtos;
        while (atual->proxProduto != NULL) {
            atual = atual->proxProduto;
        }
        atual->proxProduto = novoProduto;
    }

    printf("Produto cadastrado com sucesso.\n");
}

void listarProdutos(Produto *produtos) {
    if (produtos == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto *atual = produtos;
    while (atual != NULL) {
        printf("\n==========PRODUTOS CADASTRADOS==========\n");
        printf("Nome do Produto: %s\n", atual->nomeProduto);
        printf("Preço: %.2f\n", atual->preco);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("=========================================\n");

        atual = atual->proxProduto;
    }
}

void cadastrarCliente(ClienteEnvio **cliente) {
    int idCliente;
    char nome[100];
    char endereco[200];

    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove nova linha
    printf("Digite o endereço do cliente: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0'; // Remove nova linha

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);
    getchar(); // Limpar o buffer

    // Alocando memória para o novo cliente
    ClienteEnvio *novoCliente = (ClienteEnvio *)malloc(sizeof(ClienteEnvio));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        return;
    }

    // Preenchendo os dados do cliente
    novoCliente->idCliente = idCliente;
    novoCliente->nome = strdup(nome);
    novoCliente->endereco = strdup(endereco);
    novoCliente->produtos = NULL; // Inicialmente, sem produtos
    novoCliente->prox = NULL;

    // Inserindo o cliente na lista de clientes
    if (*cliente == NULL) {
        *cliente = novoCliente;
    } else {
        ClienteEnvio *atual = *cliente;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoCliente;
    }

    printf("Cliente cadastrado com sucesso.\n");

    // Cadastro de produtos para o cliente
    char continuar;
    do {
        printf("Deseja cadastrar um produto para este cliente? (s/n): ");
        continuar = getchar();
        getchar(); // Limpar o buffer
        if (continuar == 's' || continuar == 'S') {
            cadastrarProduto(&novoCliente->produtos);
        }
    } while (continuar == 's' || continuar == 'S');
}

// Também listaremos os produtos cadastrados no cliente.
void listarClientes(ClienteEnvio *cliente)
{
    ClienteEnvio *atual = cliente;
    while (atual != NULL) {
        printf("\n==============LISTA DE CLIENTES CADASTRADOS============================\n");
        printf("Nome: %s\nID: %d\nEndereço: %s\n", atual->nome, atual->idCliente, atual->endereco);
        
        // Listando os produtos do cliente
        Produto *produtoAtual = atual->produtos;
        if (produtoAtual != NULL) {
            printf("\n----------------Produtos do Cliente----------------\n");
            while (produtoAtual != NULL) {
                printf("Nome do Produto: %s\n", produtoAtual->nomeProduto);
                printf("Preço: %.2f\n", produtoAtual->preco);
                printf("Quantidade: %d\n", produtoAtual->quantidade);
                produtoAtual = produtoAtual->proxProduto;
                if (produtoAtual != NULL) {
                    printf("\n");
                }
            }
            printf("----------------------------------------------------\n");
        } else {
            printf("Nenhum produto cadastrado.\n");
        }
        
        atual = atual->prox;
        printf("=========================================================================\n");
}
}

void buscarCliente(ClienteEnvio *cliente)
{
    int id_Busca;
    printf("\nDigite o ID do cliente que deseja buscar: ");
    scanf("%d", &id_Busca);

    ClienteEnvio *atual = cliente;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (atual->idCliente == id_Busca)
        {
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

    if (!encontrado)
    {
        printf("Cliente com ID %d não encontrado.\n", id_Busca);
    }
}

void editarProduto(Produto *produtos)
{
    char nomeProduto[100];
    printf("Digite o nome do produto que deseja editar: ");
    scanf(" %[^\n]s", nomeProduto);

    Produto *atual = produtos;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (strcmp(atual->nomeProduto, nomeProduto) == 0)
        {
            printf("\n============== DADOS ATUAIS DO PRODUTO ==============\n");
            printf("Nome atual: %s\n", atual->nomeProduto);
            printf("Preço atual: %.2f\n", atual->preco);
            printf("Quantidade atual: %d\n", atual->quantidade);
            printf("====================================================\n");

            printf("Digite o novo nome do produto: ");
            char novoNome[100];
            scanf(" %[^\n]s", novoNome);
            free(atual->nomeProduto); // Liberar memória antiga
            atual->nomeProduto = strdup(novoNome); // Atualizar com o novo nome

            printf("Digite o novo preço do produto: ");
            scanf("%f", &atual->preco);

            printf("Digite a nova quantidade do produto: ");
            scanf("%d", &atual->quantidade);

            printf("Produto editado com sucesso!\n");

            printf("\n============== NOVOS DADOS DO PRODUTO ===============\n");
            printf("Nome: %s\n", atual->nomeProduto);
            printf("Preço: %.2f\n", atual->preco);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("====================================================\n");

            encontrado = 1;
            break;
        }
        atual = atual->proxProduto;
    }

    if (!encontrado)
    {
        printf("Produto %s não encontrado.\n", nomeProduto);
    }
}



// Faça a edição do cliente, onde o usuário poderá editar o nome e o endereço do cliente.
// e tambem a edição dos produtos
void editarCliente(ClienteEnvio *cliente)
{
    int idParaEditar;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &idParaEditar);

    ClienteEnvio *atual = cliente;
    int encontrado = 0;

    while (atual != NULL)
    {
        if (atual->idCliente == idParaEditar)
        {
            printf("\n=================== DADOS ATUAIS DO CLIENTE ===================\n");
            printf("Nome atual: %s\n", atual->nome);
            printf("Endereço atual: %s\n", atual->endereco);
            printf("==============================================================\n");

            printf("Digite o novo nome do cliente: ");
            char novoNome[100];
            scanf(" %[^\n]s", novoNome);
            free(atual->nome); // Liberar memória antiga
            atual->nome = strdup(novoNome); // Atualizar com o novo nome

            printf("Digite o novo endereço do cliente: ");
            char novoEndereco[200];
            scanf(" %[^\n]s", novoEndereco);
            free(atual->endereco); // Liberar memória antiga
            atual->endereco = strdup(novoEndereco); // Atualizar com o novo endereço

            printf("Cliente editado com sucesso!\n");

            printf("\n=================== NOVOS DADOS DO CLIENTE ===================\n");
            printf("Nome: %s\n", atual->nome);
            printf("Endereço: %s\n", atual->endereco);
            printf("==============================================================\n");

            encontrado = 1;

            char editarProdutos;
            printf("Deseja editar os produtos deste cliente? (s/n): ");
            scanf(" %c", &editarProdutos);

            if (editarProdutos == 's' || editarProdutos == 'S')
            {
                editarProduto(atual->produtos);
            }

            break;
        }
        atual = atual->prox;
    }

    if (!encontrado)
    {
        printf("Cliente com ID %d não encontrado.\n", idParaEditar);
    }
}

void excluirProdutos(Produto *produto)
{
    Produto *atual = produto;
    Produto *proxProduto;

    while (atual != NULL)
    {
        proxProduto = atual->proxProduto;
        free(atual->nomeProduto);
        free(atual);
        atual = proxProduto;
    }
}


// Excluir tambem os produtos do cliente
void excluirCliente(ClienteEnvio **cliente)
{
    int idParaExcluir;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &idParaExcluir);

    ClienteEnvio *atual = *cliente;
    ClienteEnvio *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->idCliente == idParaExcluir)
        {
            if (anterior == NULL)
            {
                *cliente = atual->prox;
            }
            else
            {
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

ClienteEnvio *retornarCliente(ClienteEnvio *cliente, int id)
{
    ClienteEnvio *atual = cliente;

    while (atual != NULL)
    {
        if (atual->idCliente == id)
        {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}
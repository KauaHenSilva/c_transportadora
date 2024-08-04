#include <print_struct.h>
#include <stdio.h>

void printDevolucao(Devolucao *devolucao)
{
  // printf("ID Rota: %d\n", devolucao->idRota);
  // printf("Status: %d\n", devolucao->andamentoEntrega);
  // for (Pacote *pacote = devolucao->pacotes; pacote != NULL; pacote = pacote->prox)
  // {
  //   printf("ID Pacote: %d\n", pacote->id_pacote);
  //   printf("Endereco: %s\n", pacote->endereco);
  //   printf("Status: Pacote Devolvido\n");
  //   for (Produto *produto = pacote->produtos; produto != NULL; produto = produto->prox)
  //   {
  //     printf("ID Produto: %d\n", produto->id_produto);
  //     printf("ID Cliente: %d\n", produto->cliente->idCliente);
  //     printf("Nome Produto: %s\n", produto->nome);
  //   }
  // }
}

void printRotaEntrega(RotaEntrega *rota)
{
  printf("Id da rota: %d\n", rota->idRota);
  switch (rota->andamentoEntrega)
  {
  case ENTREGA_FINALIZADO:
    printf("\t- Status: Entregue\n");
    break;

  case ENTREGA_EM_PROCESSO:
    printf("\t- Status: Em processo de entrega\n");
    break;
  }

  if (rota->pacote != NULL)
  {
    printf("\t- Pacote:\n");
    printPacote(rota->pacote);
  }
}

void printlistarClientes(ClienteEnvio *cliente)
{
  ClienteEnvio *atual = cliente;
  while (atual != NULL)
  {
    printCliente(atual);
    atual = atual->prox;
  }
}

void printCliente(ClienteEnvio *cliente)
{
  printf("Cliente ID: %d\n", cliente->idCliente);
  printf("\t-Nome: %s\n", cliente->nome);
  printf("\t-CPF: %s\n", cliente->cpf);
  printf("\t-Endereco: %s\n", cliente->endereco);
}

void printProduto(Produto *produto)
{
  printf("\t ID Produto: %d\n", produto->id_produto);
  printf("\t ID Cliente: %d\n", produto->cliente->idCliente);
  printf("\t Nome Produto: %s\n", produto->nome);
}

void printPacote(Pacote *pacote)
{
  printf("\t\t- ID Pacote: %d\n", pacote->id_pacote);
  printf("\t\t- Endereco: %s\n", pacote->endereco);
  Produto *produto = pacote->produtos;
  while (produto != NULL)
  {
    printf("\t\t  Produto nome %s:\n", produto->nome);
    printf("\t\t\t- ID Produto: %d\n", produto->id_produto);
    printf("\t\t\t- ID Cliente: %d\n", produto->cliente->idCliente);
    produto = produto->prox;
  }
}

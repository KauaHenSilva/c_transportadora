#include <print_struct.h>
#include <stdio.h>

void printDevolucao(Devolucao *devolucao)
{
  printf("ID Rota: %d\n", devolucao->idRota);
  printf("Status: %d\n", devolucao->status);
  for (Pacote *pacote = devolucao->pacotes; pacote != NULL; pacote = pacote->prox)
  {
    printf("ID Pacote: %d\n", pacote->id_pacote);
    printf("Endereco: %s\n", pacote->endereco);
    printf("Status: Pacote Devolvido\n");
    for (Produto *produto = pacote->produtos; produto != NULL; produto = produto->prox)
    {
      printf("ID Produto: %d\n", produto->id_produto);
      printf("ID Cliente: %d\n", produto->cliente->idCliente);
      printf("Nome Produto: %s\n", produto->nome);
    }
  }
}

void printRotaEntrega(RotaEntrega *rota)
{
  printf("Id da rota: %d\n", rota->idRota);
  switch (rota->status)
  {
  case ROTA_RECEBENDO:
    printf("\t- Status: Recebendo Produtos\n");
    break;
  case ROTA_ENTREGANDO:
    printf("\t- Status: Entregando\n");
    break;
  case ROTA_FINALIZADO:
    printf("\t- Status: Finalizado\n");
    break;
  default:
    break;
  }

  if (rota->pacotes == NULL)
  {
    printf("\t- Nenhum pacote cadastrado\n");
    return;
  }

  Pacote *aux = rota->pacotes;
  while (aux != NULL)
  {
    printf("\t- Id do pacote: %d\n", aux->id_pacote);
    printf("\t\t- Endereco do pacote: %s\n", aux->endereco);
    Produto *auxProd = aux->produtos;
    printf("\t\t\t- Produtos:\n");
    while (auxProd != NULL)
    {
      printf("\t\t\t\tO id do produto: %d\n", auxProd->id_produto);
      printf("\t\t\t\t\t- Id do cliente: %d\n", auxProd->cliente->idCliente);
      printf("\t\t\t\t\t- Nome do produto: %s\n", auxProd->nome);
      if (auxProd->andamento == ENTREGA_EM_PROCESSO)
        printf("\t\t\t\t\t- Status: Em processo de entrega\n");
      else if (auxProd->andamento == ENTREGA_FINALIZADO)
        printf("\t\t\t\t\t- Status: Entregue\n");
      auxProd = auxProd->prox;
    }
    aux = aux->prox;
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
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <stdio.h>
#include <stdlib.h>

void hello_word_rotas_entrega()
{
  printf("Hello, World! Rotas de entrega\n");
}

void criarFilaRota(FilaRota *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

void inputValoresRota(RotaEntrega *rota)
{
  printf("Digite o id da rota: ");
  scanf("%d", &rota->idRota);

  printf("Digite o nome do produto: ");
  scanf("%s", rota->nomeProduto);

  printf("Digite o endereço: ");
  scanf("%s", rota->endereco);

  printf("Digite o id do cliente: ");
  scanf("%d", &rota->idCliente);

  printf("Digite o status: ");
  scanf("%d", &rota->status);
}

void inserirRota(FilaRota *fila, RotaEntrega *newRota)
{
  if (fila->inicio == NULL)
  {
    fila->inicio = newRota;
    fila->fim = newRota;
  }
  else
  {
    RotaEntrega *aux = fila->fim;
    aux->prox = newRota;
    fila->fim = newRota;
  }
}

void finalizarRota(FilaRota *fila)
{
  if (fila->inicio == NULL)
  {
    printf("Fila vazia\n");
    return;
  }

  RotaEntrega *aux = fila->inicio;
  fila->inicio = fila->inicio->prox;

  aux = NULL;
  free(aux);

  if (fila->inicio == NULL)
    fila->fim = NULL;
}

void listarRota(FilaRota *fila)
{
  if (fila->inicio == NULL)
  {
    printf("Fila vazia\n");
  }
  else
  {
    RotaEntrega *aux = fila->inicio;
    while (aux != NULL)
    {
      printf("Id da rota: %d\n", aux->idRota);
      printf("Nome do produto: %s\n", aux->nomeProduto);
      printf("Endereço: %s\n", aux->endereco);
      printf("Id do cliente: %d\n", aux->idCliente);
      printf("Status: %d\n", aux->status);
      aux = aux->prox;
    }
  }
}

RotaEntrega *retornarRota(FilaRota *fila, int idRota)
{
  if (fila->inicio == NULL)
  {
    printf("Fila vazia\n");
    return NULL;
  }

  RotaEntrega *aux = fila->inicio;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
      return aux;
    aux = aux->prox;
  }
}


void editarRota(FilaRota *fila, int idRota, RotaEntrega *newRota)
{
  if (fila->inicio == NULL)
  {
    printf("Fila vazia\n");
    return;
  }

  RotaEntrega *aux = fila->inicio;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
    {
      aux->idRota = newRota->idRota;
      aux->nomeProduto = newRota->nomeProduto;
      aux->endereco = newRota->endereco;
      aux->idCliente = newRota->idCliente;
      aux->status = newRota->status;
      return;
    }
    aux = aux->prox;
  }

  printf("Rota não encontrada\n");
}

void adicionarEntregasNaoEfetuadas(PilhaRotaNaoEfetuada *pilha, RotaEntrega *rota)
{
  RotaNaoEfetuada *novaRota = malloc(sizeof(RotaNaoEfetuada));
  novaRota->idRota = rota->idRota;
  novaRota->nome = rota->nomeProduto;
  // novaRota->endereço = rota->endereço;
  novaRota->idCliente = rota->idCliente;
  novaRota->status = rota->status;
  novaRota->tentativas = 0;

  inserirRotaNaoEfetuada(pilha, novaRota);
}

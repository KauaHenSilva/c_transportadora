#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <stdio.h>
#include <stdlib.h>

int idRoutaCont = 1;

void printRota(RotaEntrega *rota)
{
  printf("Id da rota: %d\n", rota->idRota);
  switch (rota->status)
  {
  case RECEBENDO:
    printf("Status: Recebendo Produtos\n");
    break;
  case ENTREGANDO:
    printf("Status: Entregando\n");
    break;
  case FINALIZADO:
    printf("Status: Finalizado\n");
    break;
  default:
    break;
  }

  ClienteEnvio *aux = rota->clientes;
  while (aux != NULL)
  {
    printf("cpf: %s\n", aux->cpf);
    printf("Nome do cliente: %s\n", aux->nome);
    printf("Produtos:\n");

    Produto *auxProd = aux->produtos;
    while (auxProd != NULL)
    {
      printf("Nome do produto: %s\n", auxProd->nome);
      printf("id: %d\n", auxProd->id);
      auxProd = auxProd->prox;
    }
    aux = aux->prox;
  }
}

void criarFilaRota(FilaRota *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

void creatRota(RotaEntrega *rota, ClienteEnvio *clientes)
{
  rota->clientes = clientes;
  rota->prox = NULL;
  rota->status = RECEBENDO;
  rota->idRota = idRoutaCont++;
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

int finalizarRota(RotaEntrega *rota)
{
  ClienteEnvio *aux = rota->clientes;
  while (aux != NULL)
  {
    if (aux->status == ENTREGAR_A_CLINETE)
    {
      printf("O cliente %d não recebeu o produto\n", aux->idCliente);
      return 0;
    }
  }

  printf("Todos os clientes receberam o produto\n");
  rota->status = FINALIZADO;
  return 1;
}

void listarRotas(FilaRota *fila)
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
      switch (aux->status)
      {
      case RECEBENDO:
        printf("Status: Recebendo Produtos\n");
        break;
      case ENTREGANDO:
        printf("Status: Entregando\n");
        break;
      case FINALIZADO:
        printf("Status: Finalizado\n");
        break;
      }
      aux = aux->prox;
    }
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
      aux->clientes = newRota->clientes;
      aux->status = newRota->status;
      return;
    }
    aux = aux->prox;
  }

  printf("Rota não encontrada\n");
}

RotaEntrega *retornarRota(FilaRota *filaRota, int idRota)
{
  if (filaRota->inicio == NULL)
  {
    printf("Fila vazia\n");
    return NULL;
  }

  RotaEntrega *aux = filaRota->inicio;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
      return aux;
    aux = aux->prox;
  }

  printf("Rota não encontrada\n");
  return NULL;
}

void alterarStatusCliente(ClienteEnvio *cliente, StatusCliente status)
{
  cliente->status = status;
}

void freeFilaRota(FilaRota *filaRota)
{
  RotaEntrega *aux = filaRota->inicio;
  while (aux != NULL)
  {
    filaRota->inicio = filaRota->inicio->prox;
    free(aux);
    aux = filaRota->inicio;
  }
  filaRota->fim = NULL;
}

void freeRotaEntrega(RotaEntrega *rota)
{
  ClienteEnvio *aux = rota->clientes;
  while (aux != NULL)
  {
    rota->clientes = rota->clientes->prox;
    free(aux);
    aux = rota->clientes;
  }

  free(rota);
}

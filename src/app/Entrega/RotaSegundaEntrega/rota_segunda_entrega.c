#include "rota_segunda_entrega.h"
#include <rota_segunda_entrega.h>
#include <stdio.h>
#include <stdlib.h>

PilhaRotaNaoEfetuada *criarPilhaNaoEntregue()
{
  PilhaRotaNaoEfetuada *novo = (PilhaRotaNaoEfetuada *)malloc(sizeof(PilhaRotaNaoEfetuada));
  novo->topo = NULL;
  return novo;
}

void inserirRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, RotaEntrega *rota)
{
  RotaNaoEfetuada *novo = malloc(sizeof(RotaEntrega));
  novo->idRota = rota->idRota;
  novo->clientes = rota->clientes;
  novo->status = RECEBENDO;
  
  novo->prox = pilha->topo;
  pilha->topo = novo;
}

void removerPedido(PilhaRotaNaoEfetuada *pilha)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia ou nao foi inicializada!\n");
  }
  else
  {
    int idCliente = pilha->topo->clientes->idCliente;
    RotaNaoEfetuada *aux = pilha->topo;
    RotaNaoEfetuada *anterior = NULL;

    int cont = 0;

    while (aux != NULL)
    {
      if (aux->clientes->idCliente == idCliente)
      {
        if (anterior == NULL)
        {
          pilha->topo = aux->prox;
        }
        else
        {
          anterior->prox = aux->prox;
        }
        RotaNaoEfetuada *temp = aux;
        aux = aux->prox;
        free(temp->clientes);
        free(temp);
        cont++;
      }
      else
      {
        anterior = aux;
        aux = aux->prox;
      }
    }
    printf("O cliente com ID %d recebeu %d pedidos.\n", idCliente, cont);
  }
}

void listarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    RotaNaoEfetuada *aux = pilha->topo;
    printf("---- Rotas Nao Efetuadas ----\n");
    while (aux != NULL)
    {
      printf("ID da Rota: %d, ID do Cliente: %d\n", aux->idRota, aux->clientes->idCliente);
      printf("Status da Rota: %s\n", aux->status == ENTREGAR ? "Entregar" : "Entregue");

      aux = aux->prox;
    }
    printf("-----------------------------\n");
  }
}

void buscarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia!\n");
    return;
  }
  RotaNaoEfetuada *aux = pilha->topo;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
    {
      printf("Rota encontrada:\n");
      printf("ID da Rota: %d, ID do Cliente: %d\n", aux->idRota, aux->clientes->idCliente);
      printf("Status da Rota: %s\n", aux->status == ENTREGAR ? "Entregar" : "Entregue");
      return;
    }
    aux = aux->prox;
  }
  printf("Rota com ID %d nao encontrada.\n", idRota);
}

void editarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia!\n");
    return;
  }
  RotaNaoEfetuada *aux = pilha->topo;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
    {
      int newStatus;
      printf("ID da rota a ser editada: %d\n", aux->idRota);
      printf("Digite o novo status (Entregar = 0 / Entregue = 1): ");
      scanf("%d", &newStatus);
      if (newStatus == ENTREGAR || newStatus == ENTREGUE)
      {
        {
          aux->status = newStatus;
        }

        printf("Rota editada com sucesso\n");
      }
      aux = aux->prox;
    }
    else
    {
      printf("Rota nao efetuada nao encontrada\n");
    }
  }
}

void liberarPilhaNaoEntregue(PilhaRotaNaoEfetuada *pilha){
  RotaNaoEfetuada *aux = pilha->topo;
  RotaNaoEfetuada *temp;

  while (aux!= NULL)
  {
    temp = aux;
    aux = aux->prox;
    free(temp->clientes);
    free(temp);
  }
  free(pilha);
}
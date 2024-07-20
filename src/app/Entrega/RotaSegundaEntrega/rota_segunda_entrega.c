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

void finalizarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha)
{
  RotaNaoEfetuada *aux = pilha->topo;
  int cont = 0;
  int idCliente = pilha->topo->idRota;

  while (aux != NULL)
  {
    if (aux->idRota == idCliente)
    {
      free(aux);
      cont++;
    }
    aux = aux->prox;
  }
  printf("O cliente recebeu %d pedidos.\n", cont);
}

void listarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha)
{
  if (pilha == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    RotaNaoEfetuada *aux = pilha->topo;
    printf("---- Rotas Nao Efetuadas ----\n");
    while (aux != NULL)
    {
      printf("ID da Rota: %d\n", aux->idRota);
      aux = aux->prox;
    }
    printf("-----------------------------\n");
  }
}

void buscarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota)
{
  if (pilha == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    RotaNaoEfetuada *aux = pilha->topo;
    while (aux != NULL)
    {
      if (aux->idRota == idRota)
      {
        printf("Rota encontrada:\n");
        printf("ID da Rota: %d\n", aux->idRota);
        return;
      }
      aux = aux->prox;
    }
    printf("Rota com ID %d nao encontrada.\n", idRota);
  }
}

void editarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota)
{
  RotaNaoEfetuada *rota;
  rota = pilha->topo;
  while (rota != NULL)
  {
    if (rota->idRota == idRota)
    {
      printf("ID da rota a ser editada: %d\n", rota->idRota);
      printf("Digite o novo ID: ");
      scanf("%d", &rota->idRota);
      printf("Rota editada com sucesso\n");
      return;
    }
    rota = rota->prox;
  }
  printf("Rota nao efetuada nao encontrada\n");
}

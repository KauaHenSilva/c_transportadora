#include <rota_segunda_entrega.h>
#include <stdio.h>
#include <stdlib.h>
void hello_word_rotas_nao_efetuadas()
{
  printf("Hello, World! Rotas nao efetuadas\n");
}

Pilha *criarPilhaNaoEntregue()
{
  Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
  novo->topo = NULL;
  return novo;
}

void inserirRotaNaoEfetuada(Pilha *pilha, RotaEntrega *rota)
{
  RotaEntrega *novo = malloc(sizeof(RotaEntrega));
  novo->idCliente = rota->idCliente;
  novo->prox = pilha->topo;
  pilha->topo = novo;

}

void finalizarRotaNaoEfetuada(Pilha *pilha){
  RotaEntrega *aux = pilha->topo;
  int cont = 0;
  int idCliente = pilha->topo->idCliente;
  while (aux!= NULL)
  {
    if (aux->idCliente==idCliente)
    {
      free(aux);
      cont++;
    }
    aux = aux->prox;
  }
  printf("O cliente recebeu %d pedidos.\n", cont);
}

void listarRotaNaoEfetuada(Pilha *pilha)
{
  if (pilha == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    RotaEntrega *aux = pilha->topo;
    printf("---- Rotas Nao Efetuadas ----\n");
    while (aux != NULL)
    {
      printf("ID da Rota: %d\n", aux->idCliente);
      aux = aux->prox;
    }
    printf("-----------------------------\n");
  }
}

void buscarRotaNaoEfetuada(Pilha *pilha, int idCliente)
{
  if (pilha == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    RotaEntrega *aux = pilha->topo;
    while (aux != NULL)
    {
      if (aux->idCliente == idCliente)
      {
        printf("Rota encontrada:\n");
        printf("ID da Rota: %d\n", aux->idCliente);
        return;
      }
      aux = aux->prox;
    }
    printf("Rota com ID %d nao encontrada.\n", idCliente);
  }
}

void editarRotaNaoEfetuada(Pilha *pilha, int idCliente)
{
  RotaNaoEfetuada *rota;
  rota = pilha->topo;
  while (rota != NULL)
  {
    if (rota->idCliente == idCliente)
    {
      printf("ID da rota a ser editada: %d\n", rota->idCliente);
      printf("Digite o novo ID: ");
      scanf("%d", &rota->idCliente);
      printf("Rota editada com sucesso\n");
      return;
    }
    rota = rota->ant;
  }
  printf("Rota nao efetuada nao encontrada\n");
}
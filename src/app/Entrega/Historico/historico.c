#include <stdlib.h>
#include <stdio.h>
#include <historico.h>
#include <print_struct.h>

void adicionaHistorico(Produto *produto, HistoricoEntrega **historicoEntrega, int idRota)
{
  HistoricoEntrega *historico = (HistoricoEntrega *)malloc(sizeof(HistoricoEntrega));
  historico->produto = produto;
  historico->idRota = idRota;
  historico->prox = NULL;

  if (*historicoEntrega == NULL)
  {
    *historicoEntrega = historico;
  }
  else
  {
    HistoricoEntrega *aux = *historicoEntrega;
    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = historico;
  }
}

void listarHistorico(HistoricoEntrega *historicoEntrega)
{
  HistoricoEntrega *aux = historicoEntrega;
  if (aux == NULL)
  {
    printf("Nenhum historico de entrega cadastrado.\n");
    return;
  }

  printf("\nHistorico de entregas:\n");
  while (aux != NULL)
  {
    printf("ID Rota: %d\n", aux->idRota);

    printf("\t");
    if (aux->produto->status == REENTREGAR_A_CLINETE)
      printf("Status: %s\n", "foi entrgue ao cliente na segunda tentativa");
    else if (aux->produto->status == DEVOLVER_A_REMETENTE)
      printf("Status: %s\n", "foi devolvido ao remetente");
    else
      printf("Status: %s\n", "Entregue na primeira tentativa");

    printProduto(aux->produto, "\t");

    aux = aux->prox;
  }
  printf("\n");
}

void freeHistoricoEntrega(HistoricoEntrega **historicoEntrega)
{
  HistoricoEntrega *aux = *historicoEntrega;
  while (aux != NULL)
  {
    HistoricoEntrega *aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  *historicoEntrega = NULL;
}
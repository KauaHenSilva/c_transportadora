#include <devolucao_entrega.h>
#include <print_struct.h>
#include <historico.h>

#include <stdio.h>
#include <stdlib.h>

static int idRoutaDevolucaoCont = 1;

void hello_word_devolucao()
{
  printf("Hello, World! Devolucao\n");
}

void criarFilaDevolucao(FilaDevolucao *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

void inserirDevolucao(FilaDevolucao *fila, Produto *produto, int idRotaOriginal)
{
  Devolucao *devolucao = (Devolucao *)malloc(sizeof(Devolucao));
  devolucao->idRota = idRoutaDevolucaoCont++;
  devolucao->idRotaOriginal = idRotaOriginal;
  devolucao->produto = produto;
  devolucao->produto->status = DEVOLVER_A_REMETENTE;
  devolucao->prox = NULL;

  if (fila->fim == NULL)
  {
    fila->inicio = devolucao;
    fila->fim = devolucao;
  }
  else
  {
    fila->fim->prox = devolucao;
    fila->fim = devolucao;
  }

  devolucao->prox = NULL;
}

void finalizarDevolucao(FilaDevolucao *fila, HistoricoEntrega **historicoEntrega)
{

  while (fila->inicio != NULL)
  {
    adicionaHistorico(fila->inicio->produto, historicoEntrega, fila->inicio->idRotaOriginal);
    fila->inicio = fila->inicio->prox;
  }

  fila->fim = NULL;
}

void listarDevolucao(FilaDevolucao *fila)
{
  Devolucao *atual = fila->inicio;

  while (atual != NULL)
  {
    printDevolucao(atual);
    atual = atual->prox;
  }
}

void buscarDevolucao(FilaDevolucao *fila, int idRota)
{
  (void)fila;
  (void)idRota;
  // Devolucao *atual = fila->inicio;

  // while (atual != NULL)
  // {
  //   if (atual->idRota == idRota)
  //   {
  //     printDevolucao(atual);
  //     return;
  //   }
  //   atual = atual->prox;
  // }

  // printf("Devolucao com ID Rota %d não encontrada.\n", idRota);
}

void freeFilaDevolucao(FilaDevolucao *fila)
{
  Devolucao *aux = fila->inicio;

  while (aux != NULL)
  {
    Devolucao *temp = aux;
    aux = aux->prox;
    free(temp->produto->cliente);
    free(temp->produto);
    free(temp);
  }

  fila->inicio = NULL;
  fila->fim = NULL;
}

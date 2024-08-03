#include <devolucao_entrega.h>
#include <stdio.h>
#include <print_struct.h>

void hello_word_devolucao()
{
  printf("Hello, World! Devolucao\n");
}

void inserirDevolucao(FilaDevolucao *fila, Devolucao *devolucao)
{
  if (fila->fim == NULL)
  {
    // Se a fila estiver vazia
    fila->inicio = devolucao;
    fila->fim = devolucao;
  }
  else
  {
    // Se a fila não estiver vazia
    fila->fim->prox = devolucao;
    fila->fim = devolucao;
  }
  devolucao->prox = NULL;
}

void buscarDevolucao(FilaDevolucao *fila, int idRota)
{
  Devolucao *atual = fila->inicio;

  while (atual != NULL)
  {
    if (atual->idRota == idRota)
    {
      printDevolucao(atual);
      return;
    }
    atual = atual->prox;
  }

  printf("Devolucao com ID Rota %d não encontrada.\n", idRota);
}
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <print_struct.h>
#include <pacote.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

static int idRoutaCont = 1;

void criarFilaRotaEntrega(FilaRotaEntrega *filaRota)
{
  filaRota->inicio = NULL;
  filaRota->fim = NULL;
}

void criarRotaEntrega(RotaEntrega *rotaEntrega, Pacote *pacote)
{
  rotaEntrega->idRota = idRoutaCont++;
  rotaEntrega->pacote = pacote;
  rotaEntrega->prox = NULL;
  rotaEntrega->andamentoEntrega = ENTREGA_EM_PROCESSO;
}

void inserirRota(FilaRotaEntrega *filaRotaEntrega, RotaEntrega *newRota)
{
  if (filaRotaEntrega->inicio == NULL)
  {
    filaRotaEntrega->inicio = newRota;
    filaRotaEntrega->fim = newRota;
  }
  else
  {
    RotaEntrega *aux = filaRotaEntrega->fim;
    aux->prox = newRota;
    filaRotaEntrega->fim = newRota;
  }
}

void inserirProdutoRota(FilaRotaEntrega *filaRotaEntrega, Produto *produto)
{
  RotaEntrega *aux = filaRotaEntrega->inicio;
  while (aux != NULL)
  {
    if (aux->pacote->endereco == produto->cliente->endereco)
    {
      Produto *auxProduto = aux->pacote->produtos;
      while (auxProduto->prox != NULL)
        auxProduto = auxProduto->prox;

      auxProduto->prox = produto;
      break;
    }
    aux = aux->prox;
  }

  if (aux == NULL)
  {
    Pacote *pacote = criar_pacote(produto);

    RotaEntrega *rota = malloc(sizeof(RotaEntrega));
    criarRotaEntrega(rota, pacote);
    inserirRota(filaRotaEntrega, rota);

    printf("Rota %d cadastrada com sucesso.\n", rota->idRota);
  }
}

void listarRotas(FilaRotaEntrega *filaRotaEntrega)
{
  if (filaRotaEntrega->inicio == NULL)
  {
    printf("Fila rota entrega vazia\n");
  }
  else
  {
    RotaEntrega *aux = filaRotaEntrega->inicio;
    while (aux != NULL)
    {
      printRotaEntrega(aux);
      aux = aux->prox;
    }
  }
}

RotaEntrega *retornarRota(FilaRotaEntrega *filaRotaEntrega, int idRota)
{
  if (filaRotaEntrega->inicio == NULL)
  {
    printf("Fila vazia\n");
    return NULL;
  }

  RotaEntrega *aux = filaRotaEntrega->inicio;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
      return aux;
    aux = aux->prox;
  }

  printf("Rota não encontrada\n");
  return NULL;
}

void freeFilaRota(FilaRotaEntrega *filaRotaEntrega)
{
  RotaEntrega *aux = filaRotaEntrega->inicio;
  while (aux != NULL)
  {
    filaRotaEntrega->inicio = filaRotaEntrega->inicio->prox;
    freeRotaEntrega(aux);
    aux = filaRotaEntrega->inicio;
  }

  filaRotaEntrega->inicio = NULL;
  filaRotaEntrega->fim = NULL;
}

void freeRotaEntrega(RotaEntrega *rota)
{
  Pacote *aux = rota->pacote;
  while (aux != NULL)
  {
    rota->pacote = rota->pacote;
    freePacote(aux);
    free(aux->endereco);
    aux = rota->pacote;
  }

  free(rota);
}

void iniciarRota(FilaRotaEntrega *filaRotaEntrega)
{
  if (filaRotaEntrega->inicio == NULL)
  {
    printf("Fila vazia\n");
    return;
  }

  RotaEntrega *aux = filaRotaEntrega->inicio;
  
  while (aux != NULL)
  {
    Pacote *auxPacote = aux->pacote;
    Produto *auxProduto = auxPacote->produtos;
    while (auxProduto != NULL)
    {
      if (strcmp(auxProduto->cliente->endereco, auxPacote->endereco) == 1)
      {
        printf("O endereco do produto %d é diferente do endereco do pacote %d\n", auxProduto->id_produto, auxPacote->id_pacote);
        printf("Alguém recebeu o pacote para o cliente %d?\n", auxProduto->cliente->idCliente);
      }
      else
      {
        printf("O produto %d foi entregue para o cliente %d?\n", auxProduto->id_produto, auxProduto->cliente->idCliente);
      }

      printf("1 - Sim\n");
      printf("2 - Não\n");
      int status;
      get_int(&status, "Digite a opção desejada: ", 1, 2);

      if (status == 2)
      {
        printf("O produto %d não foi entregue para o cliente %d\n", auxProduto->id_produto, auxProduto->cliente->idCliente);
        printf("O produto será adicionado a pilha da segunda tentativa\n");
        Produto *produtoExcluido = auxProduto;
        auxPacote->produtos = auxProduto;
        free(produtoExcluido);
        printf("MENSAGEN DEV: O produto só foi excluido mande para a pilha da segunda tentativa.\n");
      }
      else
      {
        printf("O produto %d foi entregue para o cliente %d\n", auxProduto->id_produto, auxProduto->cliente->idCliente);
        Produto *produtoExcluido = auxProduto;
        auxPacote->produtos = auxProduto;
        free(produtoExcluido);
        printf("MENSAGEN DEV: O produto só foi excluido mande para o historico para fazer o score.\n");
      }
      auxProduto = auxProduto->prox;
    }
    aux = aux->prox;
  }

  filaRotaEntrega->inicio = aux;
}

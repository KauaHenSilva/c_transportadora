#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <print_struct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

int idRoutaCont = 1;
int idPacoteCont = 1;

void criarFilaRotaEntrega(FilaRotaEntrega *filaRota)
{
  filaRota->inicio = NULL;
  filaRota->fim = NULL;
}

void criarRotaEntrega(RotaEntrega *rotaEntrega, Pacote *pacote)
{
  rotaEntrega->pacotes = pacote;
  rotaEntrega->prox = NULL;
  rotaEntrega->status = ROTA_RECEBENDO;
  rotaEntrega->idRota = idRoutaCont++;
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
    if (aux->status == ROTA_FINALIZADO)
    {
      aux = aux->prox;
      continue;
    }
    if (aux->status == ROTA_ENTREGANDO)
    {
      aux = aux->prox;
      continue;
    }

    Pacote *auxPacote = aux->pacotes;

    if (auxPacote == NULL)
    {
      Pacote *pacote = malloc(sizeof(Pacote));
      pacote->id_pacote = idPacoteCont++;
      pacote->endereco = produto->cliente->endereco;
      pacote->produtos = produto;
      pacote->prox = NULL;

      aux->pacotes = pacote;
      return;
    }

    while (auxPacote->prox != NULL)
    {
      if (strcmp(auxPacote->endereco, produto->cliente->endereco) == 0)
      {
        Produto *auxProduto = auxPacote->produtos;
        while (auxProduto->prox != NULL)
          auxProduto = auxProduto->prox;

        auxProduto->prox = produto;
        return;
      }

      auxPacote = auxPacote->prox;
    }

    // Caso o ultimo pacote tenha o mesmo endereço
    if (strcmp(auxPacote->endereco, produto->cliente->endereco) == 0)
    {
      Produto *auxProduto = auxPacote->produtos;
      while (auxProduto->prox != NULL)
        auxProduto = auxProduto->prox;

      auxProduto->prox = produto;
      return;
    }

    // Caso não tenha nenhum pacote com o mesmo endereço
    Pacote *pacote = malloc(sizeof(Pacote));
    pacote->id_pacote = idPacoteCont++;
    pacote->endereco = produto->cliente->endereco;
    pacote->produtos = produto;
    pacote->prox = NULL;

    auxPacote->prox = pacote;
    aux = aux->prox;
  }

  printf("Nenhuma rota disponivel para adicionar produto\n");
}

int finalizarRota(RotaEntrega *rota)
{
  Pacote *aux = rota->pacotes;
  while (aux != NULL)
  {
    Produto *auxProduto = aux->produtos;
    while (auxProduto != NULL)
    {
      if (auxProduto->status != ENTREGAR_A_CLINETE && auxProduto->andamento != ENTREGA_FINALIZADO)
      {
        printf("O produto %s do cliente %d foi correpondido com o status %d\n", auxProduto->nome, auxProduto->cliente->idCliente, auxProduto->status);
        printf("O produto %s do cliente %d não foi entregue\n", auxProduto->nome, auxProduto->cliente->idCliente);
        return 0;
      }
      auxProduto = auxProduto->prox;
    }
    aux = aux->prox;
  }

  printf("Todos os clientes foram atendidos\n");
  rota->status = ROTA_FINALIZADO;
  return 1;
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
  Pacote *aux = rota->pacotes;
  while (aux != NULL)
  {
    rota->pacotes = rota->pacotes->prox;
    free(aux);
    aux = rota->pacotes;
  }

  free(rota);
}

void iniciarRota(FilaRotaEntrega *filaRotaEntrega)
{
  RotaEntrega *rotaIniciar = filaRotaEntrega->inicio;
  while (rotaIniciar != NULL)
  {
    if (rotaIniciar->status == ROTA_RECEBENDO)
    {
      rotaIniciar->status = ROTA_ENTREGANDO;
      break;
    }
    rotaIniciar = rotaIniciar->prox;
  }

  if (rotaIniciar == NULL)
  {
    printf("Nenhuma rota disponivel para iniciar\n");
  }

  // Entregar pacotes
  Pacote *auxPacote = rotaIniciar->pacotes;
  while (auxPacote != NULL)
  {
    for (Produto *produto = auxPacote->produtos; produto != NULL; produto = produto->prox)
    {
      if (strcmp(produto->cliente->endereco, auxPacote->endereco) == 1)
      {
        printf("O cliente %d não recebeu o produto %s pois o endereço não confere com o do sistema.\n", produto->cliente->idCliente, produto->nome);
        printf("Alguem recebeu o produto no lugar do cliente %d?\n", produto->cliente->idCliente);
        printf("1 - Sim\n");
        printf("2 - Não\n");
      }
      else
      {
        printf("O cliente %d recebeu o produto %s?\n", produto->cliente->idCliente, produto->nome);
        printf("1 - Sim\n");
        printf("2 - Não\n");
      }

      int opcao;
      get_int(&opcao, "Digite a opcao desejada: ", 1, 2);

      if (opcao == 1)
        produto->andamento = ENTREGA_FINALIZADO;
      else
        produto->status = REENTREGAR_A_CLINETE;
    }
    auxPacote = auxPacote->prox;
  }

  finalizarRota(rotaIniciar);
}

#pragma once

#include <struct_info_entrega.h>

typedef struct rotasNaoEfetuadas{
  int idRota;
  char *nome;
  int idCliente;
  int status;
  int tentativas;

  DadosEnvio *dadosEnvio;
  struct rotasNaoEfetuadas *ant;
} RotaNaoEfetuada;

typedef struct pilhaRotaNaoEfetuada {
  RotaNaoEfetuada *topo;
} PilhaRotaNaoEfetuada;

extern PilhaRotaNaoEfetuada *pilhaRotaNaoEfetuada;

// Structs Rotas Para Entrega

typedef struct rotaEntrega
{
  int idRota;
  char *nomeProduto;
  char *endereco;
  int idCliente;
  int status;

  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRota
{
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRota;

extern FilaRota *filaRota;
#pragma once

#include <struct_info_entrega.h>

typedef enum statusRota
{
  ROTA_RECEBENDO = 0,
  ROTA_ENTREGANDO = 1,
  ROTA_FINALIZADO = 2,
} StatusRota;

typedef struct rotasNaoEfetuadas
{
  int idRota;
  StatusRota status;

  Pacote *pacotes;
  struct rotasNaoEfetuadas *prox;
} RotaNaoEfetuada;

typedef struct pilhaRotaNaoEfetuada
{
  RotaNaoEfetuada *topo;
} PilhaRotaNaoEfetuada;

typedef struct rotaEntrega
{
  int idRota;
  StatusRota status;

  Pacote *pacotes;
  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRotaEntrega
{
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRotaEntrega;

typedef struct devolucao
{
  int idRota;
  StatusRota status;
  Pacote *pacotes;

  struct devolucao *prox;
} Devolucao;

typedef struct filaDevolucao
{
  Devolucao *inicio;
  Devolucao *fim;
} FilaDevolucao;
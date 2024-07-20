#pragma once

#include <struct_info_entrega.h>

typedef enum statusRota
{
  RECEBENDO = 0,
  ENTREGANDO = 1,
  FINALIZADO = 2,
} StatusRota;

typedef struct rotasNaoEfetuadas
{
  int idRota;
  StatusRota status;

  ClienteEnvio *clientes;
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

  ClienteEnvio *clientes;
  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRota
{
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRota;

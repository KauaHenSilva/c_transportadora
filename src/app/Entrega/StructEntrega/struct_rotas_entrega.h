#pragma once

#include <struct_info_entrega.h>

typedef enum andamentoEntrega
{
  ENTREGA_EM_PROCESSO = 0, /**< O produto está em processo de entrega. */
  ENTREGA_FINALIZADO = 1,  /**< O produto foi entregue. */
} AndamentoEntrega;

typedef struct rotaEntrega
{
  int idRota;
  AndamentoEntrega andamentoEntrega;

  Pacote *pacote;

  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRotaEntrega
{
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRotaEntrega;

typedef struct segundaTentativaEntega
{
  int idRota;
  int idRotaOriginal;
  AndamentoEntrega andamentoEntrega;

  Produto *produto;

  struct rotasNaoEfetuadas *prox;
} SegundaTentativaEntega;

typedef struct pilhaSegundaTentativaEntega
{
  SegundaTentativaEntega *topo;
} PilhaSegundaTentativaEntega;

typedef struct devolucao
{
  int idRota;
  int idRotaOriginal;
  AndamentoEntrega andamentoEntrega;

  Produto *produto;

  struct devolucao *prox;
} Devolucao;

typedef struct filaDevolucao
{
  Devolucao *inicio;
  Devolucao *fim;
} FilaDevolucao;
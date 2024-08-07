#pragma once

#include <struct_info_entrega.h>

typedef struct rotaEntrega
{
  int idRota;
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
  Produto *produto;

  struct segundaTentativaEntega *prox;
} SegundaTentativaEntega;

typedef struct pilhaSegundaTentativaEntega
{
  SegundaTentativaEntega *topo;
} PilhaSegundaTentativaEntega;

typedef struct devolucao
{
  int idRota;
  int idRotaOriginal;
  Produto *produto;

  struct devolucao *prox;
} Devolucao;

typedef struct filaDevolucao
{
  Devolucao *inicio;
  Devolucao *fim;
} FilaDevolucao;

typedef struct scoreRota
{
  int ponto;
  int idRota;
  struct scoreRota *prox;
} ScoreRota;

typedef struct historicoEntrega
{
  Produto *produto;
  int idRota;

  struct historicoEntrega *prox;
} HistoricoEntrega;
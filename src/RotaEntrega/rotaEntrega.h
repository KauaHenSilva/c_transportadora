#pragma once
#include "../RotaNaoEfetuada/rotaNaoEfetuda.h"

typedef struct rotaEntrega
{
  int idRota;
  char *nomeProduto;
  char *endereço;
  int idCliente;
  int status;

  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRota
{
  rotaEntrega *inicio;
  rotaEntrega *fim;
} FilaRota;

extern FilaRota *rotas;

void inserirRota(FilaRota *fila, RotaEntrega *rota);
void finalizarRota(FilaRota *fila);
void listarRota(FilaRota *fila);
void buscarRota(FilaRota *fila, int idRota);
void editarRota(FilaRota *fila, int idRota);

void adicionarEntregasNaoEfetuadas(FilaRota *fila, RotaNaoEfetuada *rotaNaoEfetuada);

#pragma once
#include <rota_nao_efetuada.h>

void hello_word_rotas_entrega();

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
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRota;

extern FilaRota *rotas;

void inserirRota(FilaRota *fila, RotaEntrega *rota);
void finalizarRota(FilaRota *fila);
void listarRota(FilaRota *fila);
void buscarRota(FilaRota *fila, int idRota);
void editarRota(FilaRota *fila, int idRota);

void adicionarEntregasNaoEfetuadas(FilaRota *fila, RotaNaoEfetuada *rotaNaoEfetuada);

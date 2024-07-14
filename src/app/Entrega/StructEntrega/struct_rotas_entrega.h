#pragma once

#include <struct_info_entrega.h>

typedef struct rotasNaoEfetuadas{
  int idRota;
  char *nome;
  int idCliente;
  int status;
  int tentativas;

  DadosEnvio *dadosEnvio; // Aqui vai ser armazenado os endereços que vao ser tentados entregar

  struct rotasNaoEfetuadas *ant; // Nesseario para ter acesso ao elemento anterior
} RotaNaoEfetuada;

typedef struct pilhaRotaNaoEfetuada {
  RotaNaoEfetuada *topo;
} PilhaRotaNaoEfetuada;

// Structs Rotas Para Entrega

typedef struct rotaEntrega
{
  int idRota;
  char *nomeProduto;
  char *endereco; // Temporario
  int idCliente;
  int status;

  DadosEnvio *dadosEnvio; // Aqui vai ser armazenado os endereços que vao ser tentados entregar

  struct rotaEntrega *prox;
} RotaEntrega;

typedef struct FilaRota
{
  RotaEntrega *inicio;
  RotaEntrega *fim;
} FilaRota;

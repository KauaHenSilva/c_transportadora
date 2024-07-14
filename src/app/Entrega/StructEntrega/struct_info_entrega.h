#pragma once

// Structs Produtos

typedef struct produtos
{
  int idProduto;
  char *nome;
  char *descricao;
  float valor;
  struct produtos *prox;
} Produtos;

// Structs Dados de Envio

typedef struct dadosEnvio
{
  int idRota;
  char *endereço;
  int idCliente;
  int status;
  
  Produtos *produtos;
  struct dadosEnvio *prox;
} DadosEnvio;
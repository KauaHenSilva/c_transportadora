#pragma once

typedef struct devolucao{
  int idRota;
  char *nomeProduto;
  char *endereço;
  int idCliente;
  int status;
  int tentativas;

  struct rotasNaoEfetuadas *prox;
} Devolucao;

typedef struct filaDevolucao{
  Devolucao *inicio;
  Devolucao *fim;
} FilaDevolucao;

void inserirDevolucao(FilaDevolucao *fila, Devolucao *devolucao); // Flavio
void finalizarDevolucao(FilaDevolucao *fila); // Kaua
void listarDevolucao(FilaDevolucao *fila); // Raisa
void buscarDevolucao(FilaDevolucao *fila, int idRota); // Falvio
void editarDevolucao(FilaDevolucao *fila, int idRota); // Kaua

#pragma once

void hello_word_rotas_nao_efetuadas();

typedef struct rotasNaoEfetuadas{
  int idRota;
  char *nome;
  char *endereço;
  int idCliente;
  int status;
  int tentativas;

  struct rotasNaoEfetuadas *ant;
} RotaNaoEfetuada;

typedef struct pilha {
  RotaNaoEfetuada *topo;
} Pilha;

void inserirRotaNaoEfetuada(Pilha *pilha, RotaNaoEfetuada *rotaNaoEfetuada);
void finalizarRotaNaoEfetuada(Pilha *pilha);
void listarRotaNaoEfetuada(Pilha *pilha);
void buscarRotaNaoEfetuada(Pilha *pilha, int idRota);
void editarRotaNaoEfetuada(Pilha *pilha, int idRota);

void adicionarNaFilaDevolucao(Pilha *pilha, RotaNaoEfetuada *rotaNaoEfetuada);
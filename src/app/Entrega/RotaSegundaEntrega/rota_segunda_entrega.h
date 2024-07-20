#pragma once

#include <struct_rotas_entrega.h>

typedef struct pilha {
  RotaEntrega *topo;
} Pilha;

void hello_word_rotas_nao_efetuadas();
Pilha *criarPilhaNaoEntregue();
void inserirRotaNaoEfetuada(Pilha *pilha, RotaEntrega *rota);
finalizarRotaNaoEfetuada(Pilha *pilha);
void listarRotaNaoEfetuada(Pilha *pilha);
void buscarRotaNaoEfetuada(Pilha *pilha, int idRota);
void editarRotaNaoEfetuada(Pilha *pilha, int idRota);
#pragma once

#include <struct_rotas_entrega.h>

void hello_word_rotas_nao_efetuadas();

void inserirRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, RotaNaoEfetuada *rotaNaoEfetuada);
void finalizarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha);
void listarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha);
void buscarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota);
void editarRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, int idRota);
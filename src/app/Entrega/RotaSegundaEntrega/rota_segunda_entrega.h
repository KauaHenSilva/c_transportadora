#pragma once

#include <struct_rotas_entrega.h>

PilhaRotaNaoEfetuada  *criarPilhaNaoEntregue();
void inserirRotaNaoEfetuada(PilhaRotaNaoEfetuada *pilha, RotaEntrega *rota);
void removerPedido(PilhaRotaNaoEfetuada *pilha);
void listarRotaNaoEfetuada(PilhaRotaNaoEfetuada  *pilha);
void buscarRotaNaoEfetuada(PilhaRotaNaoEfetuada  *pilha, int idRota);
void editarRotaNaoEfetuada(PilhaRotaNaoEfetuada  *pilha, int idRota);
void liberarPilhaNaoEntregue(PilhaRotaNaoEfetuada *pilha);
#pragma once

#include <struct_rotas_entrega.h>

PilhaSegundaTentativaEntega *criarPilhaNaoEntregue();
void inserirRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, Produto *produto, int id_rota_original);
void removerPedido(PilhaSegundaTentativaEntega *pilha);
void listarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha);
void buscarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void editarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void liberarPilhaNaoEntregue(PilhaSegundaTentativaEntega *pilha);
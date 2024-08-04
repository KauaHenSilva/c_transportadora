#pragma once

#include <struct_rotas_entrega.h>

void criarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
void inserirRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, Produto *produto, int id_rota_original);
void removerPedido(PilhaSegundaTentativaEntega *pilha);
void listarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
void buscarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void editarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void freePilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
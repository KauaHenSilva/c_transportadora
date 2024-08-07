#pragma once

#include <struct_rotas_entrega.h>

void criarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
void inserirRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, Produto *produto, int id_rota_original);
void removerPedido(PilhaSegundaTentativaEntega *pilha);
void listarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
void buscarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void editarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota);
void finalizarSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha, FilaDevolucao *filadevolucao, HistoricoEntrega **historicoEntrega);
void freePilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha);
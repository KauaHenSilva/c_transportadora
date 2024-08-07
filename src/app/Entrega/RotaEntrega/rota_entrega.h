// void editarRota(FilaRotaEntrega *filaRotaEntrega, int idRota, RotaEntrega *newRota);

#pragma once

#include <struct_rotas_entrega.h>

void criarFilaRotaEntrega(FilaRotaEntrega *filaRotaEntrega);
void criarRotaEntrega(RotaEntrega *rotaEntrega, Pacote *pacote);
void inserirRota(FilaRotaEntrega *filaRotaEntrega, RotaEntrega *newRota);
void inserirProdutoRota(FilaRotaEntrega *filaRotaEntrega, Produto *produto);
void listarRotas(FilaRotaEntrega *filaRotaEntrega);
void iniciarRota(FilaRotaEntrega *filaRotaEntrega, PilhaSegundaTentativaEntega *pilha, HistoricoEntrega **historico);
RotaEntrega *retornarRota(FilaRotaEntrega *filaRotaEntrega, int idRota);

void freeRotaEntrega(RotaEntrega *rota);
void freeFilaRota(FilaRotaEntrega *filaRotaEntrega);
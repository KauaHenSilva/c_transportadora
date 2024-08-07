#pragma once

#include <struct_rotas_entrega.h>

void hello_word_devolucao();

void criarFilaDevolucao(FilaDevolucao *pilha);
void inserirDevolucao(FilaDevolucao *fila, Produto *produto, int idRotaOriginal);
void finalizarDevolucao(FilaDevolucao *fila, HistoricoEntrega **historicoEntrega);
void listarDevolucao(FilaDevolucao *fila);
void buscarDevolucao(FilaDevolucao *fila, int idRota);
void editarDevolucao(FilaDevolucao *fila, int idRota);
void freeFilaDevolucao(FilaDevolucao *fila);

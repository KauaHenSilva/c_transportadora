#pragma once

#include <struct_rotas_entrega.h>

void hello_word_devolucao();

void inserirDevolucao(FilaDevolucao *fila, Devolucao *devolucao); // Flavio
void finalizarDevolucao(FilaDevolucao *fila); // Kaua
void listarDevolucao(FilaDevolucao *fila); // Raisa
void buscarDevolucao(FilaDevolucao *fila, int idRota); // Falvio
void editarDevolucao(FilaDevolucao *fila, int idRota); // Kaua

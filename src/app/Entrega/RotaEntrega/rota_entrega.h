#pragma once

#include <struct_rotas_entrega.h>

void hello_word_rotas_entrega();

void inputValoresRota(RotaEntrega *rotaPrencher); // Sem Test
void listarRota(FilaRota *filaRota); // Sem Test

void criarFilaRota(FilaRota *filaRota);
void editarRota(FilaRota *filaRota, int idRota, RotaEntrega *newRota);
void finalizarRota(FilaRota *filaRota);
void inserirRota(FilaRota *filaRota, RotaEntrega *newRota);
RotaEntrega* retornarRota(FilaRota *filaRota, int idRota);

void adicionarEntregasNaoEfetuadas(PilhaRotaNaoEfetuada *pilha, RotaEntrega *rota);

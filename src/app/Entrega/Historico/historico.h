#pragma once
#include <struct_rotas_entrega.h>
#include <struct_info_entrega.h>

void adicionaHistorico(Produto *produto, HistoricoEntrega **historicoEntrega, int idRota);
void listarHistorico(HistoricoEntrega *historicoEntrega);
void freeHistoricoEntrega(HistoricoEntrega **historicoEntrega);
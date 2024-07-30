#pragma once

#include <struct_rotas_entrega.h>

void criarFilaRota(FilaRota *filaRota);
void creatRota(RotaEntrega *rota, ClienteEnvio *clientes);
void inserirRota(FilaRota *filaRota, RotaEntrega *newRota);
void listarRotas(FilaRota *filaRota);
void editarRota(FilaRota *filaRota, int idRota, RotaEntrega *newRota);

RotaEntrega *retornarRota(FilaRota *filaRota, int idRota);

int finalizarRota(RotaEntrega *rota);
void printRota(RotaEntrega *rota);
void alterarStatusCliente(ClienteEnvio *cliente, StatusCliente status);
void freeFilaRota(FilaRota *filaRota);
void freeRotaEntrega(RotaEntrega *rota);
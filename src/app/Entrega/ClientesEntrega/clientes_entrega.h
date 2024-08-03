#pragma once

#include <struct_info_entrega.h>

void cadastrarCliente(ClienteEnvio **cliente);
int listarClientes(ClienteEnvio *cliente);
void editarCliente(ClienteEnvio *cliente);
void excluirCliente(ClienteEnvio **cliente);

int validarCPF(ClienteEnvio *cliente, char *cpf);
void freeClientes(ClienteEnvio **cliente);
ClienteEnvio *retornarCliente(ClienteEnvio *cliente, int id);

Produto *cadrastrarProduto(ClienteEnvio *cliente);
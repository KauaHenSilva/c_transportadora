#pragma once

typedef struct clientes{
  int idCliente;
  char *nome;
  char *endereço;

  struct clientes *prox;
} Clientes;

extern Clientes *clientes;

void cadastrarCliente(Clientes **cliente);
void listarClientes(Clientes *cliente);
void buscarCliente(Clientes *cliente, int idCliente);
void editarCliente(Clientes *cliente, int idCliente);
void excluirCliente(Clientes **cliente, int idCliente);


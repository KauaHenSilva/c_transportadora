#pragma once

void hello_word_clientes();

typedef struct clientes{
  int idCliente;
  char *nome;
  char *endereco;

  struct clientes *prox;
} Clientes;

extern Clientes *clientes;

void cadastrarCliente(Clientes **cliente);//feito
void listarClientes(Clientes *cliente);//feito
void buscarCliente(Clientes *cliente);//feito
void editarCliente(Clientes *cliente);//feito
void excluirCliente(Clientes **cliente);//feito


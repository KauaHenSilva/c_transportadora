#include <clientes.h>
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <devolucao_entrega.h>
#include <score.h>


int main()
{
  
  
  hello_word_clientes();
  cadastrarCliente(&clientes);
  listarClientes(clientes);
  buscarCliente(clientes);
  editarCliente(clientes);
  excluirCliente(&clientes);
  //hello_word_devolucao();
  //hello_word_rotas_entrega();
  //hello_word_rotas_nao_efetuadas();
  //hello_word_score();
  return 0;
}
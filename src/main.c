#include <clientes.h>
#include <devolucao.h>
#include <rota_entrega.h>
#include <rota_nao_efetuada.h>
#include <score.h>


int main()
{

  
  hello_word_clientes();
  cadastrarCliente(&clientes);
  listarClientes(clientes);
  buscarCliente(clientes);
  editarCliente(clientes);
  //hello_word_devolucao();
  //hello_word_rotas_entrega();
  //hello_word_rotas_nao_efetuadas();
  //hello_word_score();
  return 0;
}
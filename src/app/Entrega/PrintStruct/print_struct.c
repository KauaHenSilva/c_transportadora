#include <print_struct.h>
#include <stdio.h>

void printDevolucao(Devolucao *devolucao)
{
  printf("ID Rota: %d\n", devolucao->idRota);
  printf("ID Rota Original: %d\n", devolucao->idRotaOriginal);
  printProduto(devolucao->produto, "\t");
}

void printRotaEntrega(RotaEntrega *rota)
{
  printf("Id da rota: %d\n", rota->idRota);

  if (rota->pacote != NULL)
  {
    printf("\t- Pacote:\n");
    printPacote(rota->pacote);
  }
}

void printlistarClientes(ClienteEnvio *cliente)
{
  ClienteEnvio *atual = cliente;
  while (atual != NULL)
  {
    printCliente(atual);
    atual = atual->prox;
  }
}

void printCliente(ClienteEnvio *cliente)
{
  printf("Cliente ID: %d\n", cliente->idCliente);
  printf("\t-Nome: %s\n", cliente->nome);
  printf("\t-CPF: %s\n", cliente->cpf);
  printf("\t-Endereco: %s\n", cliente->endereco);
}

void printProduto(Produto *produto, char *espaco)
{
  printf("%s ID Produto: %d\n", espaco, produto->id_produto);
  printf("%s ID Cliente: %d\n", espaco, produto->cliente->idCliente);
  printf("%s Nome Produto: %s\n", espaco, produto->nome);
}

void printPacote(Pacote *pacote)
{
  printf("\t\t- ID Pacote: %d\n", pacote->id_pacote);
  printf("\t\t- Endereco: %s\n", pacote->endereco);
  Produto *produto = pacote->produtos;
  while (produto != NULL)
  {
    printf("\t\t ID Produto: %d\n", produto->id_produto);
    printf("\t\t\t- Produto nome %s:\n", produto->nome);
    printf("\t\t\t- Cliente nome: %s\n", produto->cliente->nome);
    produto = produto->prox;
  }
}

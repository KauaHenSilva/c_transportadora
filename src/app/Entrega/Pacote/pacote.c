#include <pacote.h>
#include <stdlib.h>
#include <stdio.h>

static int idPacoteCont = 1;

Pacote *criar_pacote(Produto *produto)
{
  Pacote *pacote = (Pacote *)malloc(sizeof(Pacote));
  pacote->id_pacote = idPacoteCont++;
  pacote->endereco = produto->cliente->endereco;
  pacote->produtos = produto;
  return pacote;
}

void freePacote(Pacote *pacote)
{
  Produto *aux = pacote->produtos;
  while (aux != NULL)
  {
    Produto *aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  free(pacote);
}

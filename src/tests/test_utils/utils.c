#include <struct_rotas_entrega.h>
#include <utils.h>
#include <stdlib.h>
#include <string.h>

void CriarRotaEntrega(RotaEntrega *rota, char *endereco, char *nomeProduto, int idCliente, int idRota)
{
  rota->endereco = endereco;
  rota->nomeProduto = nomeProduto;
  rota->idCliente = idCliente;
  rota->idRota = idRota;
}

void verificarRota(RotaEntrega *rota, char *endereco, char *nomeProduto, int idCliente, int idRota)
{
  if (!(strcmp(rota->endereco, endereco) == 0 &&
        strcmp(rota->nomeProduto, nomeProduto) == 0 &&
        rota->idCliente == idCliente &&
        rota->idRota == idRota))
  {
    exit(1);
  }
}
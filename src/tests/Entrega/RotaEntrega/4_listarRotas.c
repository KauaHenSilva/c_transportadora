#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rota_entrega.h>
#include <utils.h>

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  RotaEntrega *rota = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota, NULL);
  inserirRota(fila, rota);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota2, NULL);
  inserirRota(fila, rota2);

  RotaEntrega *rota3 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota3, NULL);
  inserirRota(fila, rota3);

  listarRotas(fila);

  freeFilaRota(fila);
  return 0;
}

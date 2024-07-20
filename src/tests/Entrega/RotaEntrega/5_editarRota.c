#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <rota_entrega.h>

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  RotaEntrega *rota = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota, NULL);
  inserirRota(fila, rota);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota2, NULL);
  rota2->status = 1;

  editarRota(fila, rota->idRota, rota2);
  verificarRota(fila->inicio, 2, 1);

  freeFilaRota(fila);
  return 0;
}
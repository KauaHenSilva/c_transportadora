#include <stdio.h>
#include <stdlib.h>
#include <rota_entrega.h>

int main()
{
  RotaEntrega *rota = (RotaEntrega *)calloc(sizeof(RotaEntrega), 1);
  creatRota(rota, NULL);

  if (rota->idRota == 0)
    return 1;

  freeRotaEntrega(rota);
  return 0;
}
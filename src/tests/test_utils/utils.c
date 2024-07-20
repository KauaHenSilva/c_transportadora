#include <struct_rotas_entrega.h>
#include <utils.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void verificarRota(RotaEntrega *rota, int idRota , StatusRota status)
{
  if (!(rota->idRota == idRota && rota->status == status))
  {
    printf("Erro ao criar rota!\n");
    exit(1);
  }
}
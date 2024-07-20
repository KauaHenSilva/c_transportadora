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

  verificarRota(fila->inicio, 1, 0);
  verificarRota(fila->fim, 1, 0);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota2, NULL);
  inserirRota(fila, rota2);

  verificarRota(fila->inicio, 1, 0);
  verificarRota(fila->fim, 2, 0);

  RotaEntrega *rota3 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota3, NULL);
  inserirRota(fila, rota3);

  verificarRota(fila->inicio, 1, 0);
  verificarRota(fila->fim, 3, 0);

  freeFilaRota(fila);
  return 0; 
}

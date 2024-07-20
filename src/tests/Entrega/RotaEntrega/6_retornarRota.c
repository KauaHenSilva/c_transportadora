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
  inserirRota(fila, rota2);

  RotaEntrega *rota3 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota3, NULL);
  inserirRota(fila, rota3);

  RotaEntrega *result1 = retornarRota(fila, 1);
  verificarRota(result1, 1, 0);

  RotaEntrega *result2 = retornarRota(fila, 2);
  verificarRota(result2, 2, 0);

  RotaEntrega *result3 = retornarRota(fila, 3);
  verificarRota(result3, 3, 0);


  freeFilaRota(fila);
  return 0;
}
#include <stdlib.h>
#include <rota_entrega.h>
#include <utils.h> 

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  RotaEntrega *rota = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota, NULL);

  RotaEntrega *rota1 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota1, NULL);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  creatRota(rota2, NULL);

  inserirRota(fila, rota);
  inserirRota(fila, rota1);
  inserirRota(fila, rota2);
  
  finalizarRota(retornarRota(fila, 3));

  verificarRota(fila->inicio, 1, RECEBENDO);
  verificarRota(fila->fim, 3, FINALIZADO);

  return 0;
}

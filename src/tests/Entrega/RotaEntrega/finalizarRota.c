#include <stdlib.h>
#include <rota_entrega.h>
#include <utils.h> 

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  RotaEntrega *rota = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota, "Rua 1", "Produto 1", 1, 1);

  inserirRota(fila, rota);
  finalizarRota(fila);

  if(!(fila->fim == NULL))
    return 1;

  if (!(fila->inicio == NULL))
    return 2;

  RotaEntrega *rota1 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota1, "Rua 2", "Produto 2", 2, 2);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota2, "Rua 3", "Produto 3", 3, 3);

  inserirRota(fila, rota1);
  inserirRota(fila, rota2);
  finalizarRota(fila);

  verificarRota(fila->inicio, "Rua 3", "Produto 3", 3, 3);
  verificarRota(fila->fim, "Rua 3", "Produto 3", 3, 3);

  return 0;
}

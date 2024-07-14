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
  CriarRotaEntrega(rota, "Rua 1", "Produto 1", 1, 1);
  inserirRota(fila, rota);

  verificarRota(fila->inicio, "Rua 1", "Produto 1", 1, 1);
  verificarRota(fila->fim, "Rua 1", "Produto 1", 1, 1);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota2, "Rua 2", "Produto 2", 2, 2);
  inserirRota(fila, rota2);

  verificarRota(fila->inicio, "Rua 1", "Produto 1", 1, 1);
  verificarRota(fila->fim, "Rua 2", "Produto 2", 2, 2);

  RotaEntrega *rota3 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota3, "Rua 3", "Produto 3", 3, 3);
  inserirRota(fila, rota3);

  verificarRota(fila->inicio, "Rua 1", "Produto 1", 1, 1);
  verificarRota(fila->fim, "Rua 3", "Produto 3", 3, 3);

  return 0; 
}

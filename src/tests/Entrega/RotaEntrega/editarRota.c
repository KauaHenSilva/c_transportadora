#include <stdio.h>
#include <stdlib.h> 
#include <utils.h>
#include <rota_entrega.h>

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  RotaEntrega *rota = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota, "Rua 1", "Produto 1", 1, 1);
  inserirRota(fila, rota);

  RotaEntrega *rota2 = (RotaEntrega *)malloc(sizeof(RotaEntrega));
  CriarRotaEntrega(rota2, "Rua 2", "Produto 2", 2, 2);

  editarRota(fila, rota->idRota, rota2);
  verificarRota(fila->inicio, "Rua 2", "Produto 2", 2, 2);
    
  return 0;
}
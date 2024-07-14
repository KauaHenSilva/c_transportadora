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
  
  RotaEntrega *rota_final = retornarRota(fila, rota->idRota);
  verificarRota(rota_final, "Rua 1", "Produto 1", 1, 1);
    
  return 0;
}
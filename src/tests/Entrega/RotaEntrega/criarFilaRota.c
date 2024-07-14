#include <stdio.h>
#include <stdlib.h>
#include <rota_entrega.h>

int main()
{
  FilaRota *fila = (FilaRota *)malloc(sizeof(FilaRota));
  criarFilaRota(fila);

  if(!(fila->inicio == NULL && fila->fim == NULL))
    return 1;
    
  return 0;
}
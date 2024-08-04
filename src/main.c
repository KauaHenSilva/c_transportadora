#include <clientes_entrega.h>
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
// #include <devolucao_entrega.h>
// #include <score.h>
#include <menu.h>

#include <stdio.h>
#include <stdlib.h>

ClienteEnvio *allClientes = NULL;
FilaRotaEntrega filaRotaEntrega;
PilhaSegundaTentativaEntega pilhaSegundaTentativaEntega;

int main()
{
  criarFilaRotaEntrega(&filaRotaEntrega);
  criarPilhaSegundaTentativaEntega(&pilhaSegundaTentativaEntega);

  menuDosMenus();

  freeFilaRota(&filaRotaEntrega);
  freeClientes(&allClientes);
  freePilhaSegundaTentativaEntega(&pilhaSegundaTentativaEntega);
  return 0;
}
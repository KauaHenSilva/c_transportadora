#include <clientes_entrega.h>
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <devolucao_entrega.h>
#include <menu.h>

#include <stdio.h>
#include <stdlib.h>

ClienteEnvio *allClientes = NULL;
HistoricoEntrega *historicoEntrega = NULL;

FilaRotaEntrega filaRotaEntrega;
PilhaSegundaTentativaEntega pilhaSegundaTentativaEntega;
FilaDevolucao filaDevolucaoEntrega;

int main()
{
  criarFilaRotaEntrega(&filaRotaEntrega);
  criarPilhaSegundaTentativaEntega(&pilhaSegundaTentativaEntega);
  criarFilaDevolucao(&filaDevolucaoEntrega);

  menuDosMenus();

  freeFilaRota(&filaRotaEntrega);
  freePilhaSegundaTentativaEntega(&pilhaSegundaTentativaEntega);
  freeFilaDevolucao(&filaDevolucaoEntrega);

  freeClientes(&allClientes);
  freeHistoricoEntrega(&historicoEntrega);
  return 0;
}
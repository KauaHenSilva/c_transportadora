#include <clientes_entrega.h>
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <devolucao_entrega.h>
#include <score.h>

#include <stdio.h>
#include <stdlib.h>

FilaRota filaRota;

void menuRotaEntrega()
{
  int opcao;
  do
  {
    printf("1 - Criar rota\n");
    printf("2 - Listar rotas\n");
    printf("3 - Editar rota\n");
    printf("4 - Finalizar rota\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      RotaEntrega *rota = malloc(sizeof(RotaEntrega));
      ClienteEnvio *clientes = criarClientes();
      creatRota(rota, clientes);
      inserirRota(&filaRota, rota);
      break;
    }
    case 2:
    {
      listarRotas(&filaRota);
      break;
    }
    case 3:
    {
      int idRota;
      printf("Digite o id da rota que deseja editar: ");
      scanf("%d", &idRota);
      RotaEntrega *rota = retornarRota(&filaRota, idRota);
      if (rota != NULL)
      {
        editarRota(&filaRota, idRota, rota);
      }
      else
      {
        printf("Rota nao encontrada!\n");
      }
      break;
    }
    case 4:
    {
      int idRota;
      printf("Digite o id da rota que deseja finalizar: ");
      scanf("%d", &idRota);
      RotaEntrega *rota = retornarRota(&filaRota, idRota);
      if (rota != NULL)
      {
        finalizarRota(rota);
      }
      else
      {
        printf("Rota nao encontrada!\n");
      }
      break;
    }
    case 0:
    {
      break;
    }
    }
  } while (opcao != 0);
}

int main()
{
  criarFilaRota(&filaRota);
  menuRotaEntrega();
  return 0;
}
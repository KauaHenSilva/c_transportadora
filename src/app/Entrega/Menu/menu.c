#include <menu.h>
#include <struct_info_entrega.h>
#include <struct_rotas_entrega.h>
#include <rota_entrega.h>
#include <rota_segunda_entrega.h>
#include <devolucao_entrega.h>
#include <clientes_entrega.h>
#include <print_struct.h>
#include <utils.h>
#include <historico.h>

#include <stdio.h>
#include <stdlib.h>

extern FilaRotaEntrega filaRotaEntrega;
extern PilhaSegundaTentativaEntega pilhaSegundaTentativaEntega;
extern FilaDevolucao filaDevolucaoEntrega;

extern ClienteEnvio *allClientes;
extern HistoricoEntrega *historicoEntrega;

void menuRotaEntrega()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Adicionar produto a rota\n");
    printf("2 - Listar rota\n");
    printf("3 - Iniciar rota\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 3);

    switch (opcao)
    {
    case SAIR_MENU_ROTA_ENTREGA:
    {
      break;
    }
    // case CADASTRAR_ROTA:
    // {
    //   RotaEntrega *rota = malloc(sizeof(RotaEntrega));
    //   Pacote *pacote = NULL;

    //   criarRotaEntrega(rota, pacote);
    //   inserirRota(&filaRotaEntrega, rota);

    //   printf("Rota %d cadastrada com sucesso.\n", rota->idRota);
    //   break;
    // }
    case LISTAR_ROTAS:
    {
      printf("\nRotas cadastradas:\n");
      listarRotas(&filaRotaEntrega);
      printf("\n");
      break;
    }
    case ADICIONAR_PRODUTO:
    {
      if (filaDevolucaoEntrega.inicio != NULL)
      {
        printf("Existem produtos na fila de devolucao, finalize a devolucao antes de adicionar novos produtos a rota.\n");
        break;
      }

      if (pilhaSegundaTentativaEntega.topo != NULL)
      {
        printf("Existem produtos na pilha de segunda tentativa de entrega, finalize a segunda tentativa antes de adicionar novos produtos a rota.\n");
        break;
      }

      Produto *produto = cadrastrarProduto(allClientes);
      if (!produto)
        break;

      inserirProdutoRota(&filaRotaEntrega, produto);
      break;
    }
    case INICIAR_ROTA:
    {
      iniciarRota(&filaRotaEntrega, &pilhaSegundaTentativaEntega, &historicoEntrega);
      break;
    }
    }
    pause();
  } while (opcao != 0);
}

void menuCliente()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Listar clientes\n");
    printf("3 - Editar cliente (ID)\n");
    printf("4 - Excluir cliente (ID)\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 4);

    switch (opcao)
    {
    case SAIR_MENU_CLIENTE:
    {
      break;
    }
    case CADASTRAR_CLIENTE:
    {
      cadastrarCliente(&allClientes);
      break;
    }
    case LISTAR_CLIENTES:
    {
      listarClientes(allClientes);
      break;
    }
    case EDITAR_CLIENTE:
    {
      if (listarClientes(allClientes))
        break;

      editarCliente(allClientes);
      break;
    }
    case EXCLUIR_CLIENTE:
    {
      if (listarClientes(allClientes))
        break;

      excluirCliente(&allClientes);
      break;
    }
    }
    pause();
  } while (opcao != 0);
}

void menuSegundaEntrega()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Listar Segunda entrega\n");
    printf("2 - Iniciar segunda entrega\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 2);

    switch (opcao)
    {
    case SAIR_MENU_SEGUNDA_ENTREGA:
    {
      break;
    }
    case LISTAR_SEGUNDA_ENTREGA:
    {
      listarPilhaSegundaTentativaEntega(&pilhaSegundaTentativaEntega);
      break;
    }
    case INICIAR_SEGUNDA_ENTREGA:
    {
      finalizarSegundaTentativaEntega(&pilhaSegundaTentativaEntega, &filaDevolucaoEntrega, &historicoEntrega);
      break;
    }
    }
    pause();
  } while (opcao != 0);
}

void menuDevolucao()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Listar devolucao\n");
    printf("2 - Finalizar devolucao\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 2);

    switch (opcao)
    {
    case SAIR_MENU_DEVOLUCAO:
    {
      break;
    }
    case LISTAR_DEVOLUCAO:
    {
      listarDevolucao(&filaDevolucaoEntrega);
      break;
    }
    case INICIAR_DEVOLUCAO:
    {

      finalizarDevolucao(&filaDevolucaoEntrega, &historicoEntrega);
      break;
    }
    }
    pause();
  } while (opcao != 0);
}

void menuHistoricoScore()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Listar historico\n");
    printf("2 - Exibir score\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 2);

    switch (opcao)
    {
    case SAIR_MENU_HISTORICO:
    {
      break;
    }
    case LISTAR_HISTORICO:
    {
      listarHistorico(historicoEntrega);
      break;
    }
    case EXIBIR_SCORE:
    {
      printf("Não implementado\n");
      // exibirScore();
      break;
    }
    }
    pause();
  } while (opcao != 0);
}

void menuDosMenus()
{
  int opcao;
  do
  {
    system("clear || cls");
    printf("1 - Menu de clientes\n");
    printf("2 - Menu de rotas\n");
    printf("3 - Menu de segunda entrega\n");
    printf("4 - Menu de devolucao\n");
    printf("5 - Menu de score/historico\n");
    printf("0 - Sair\n");
    get_int(&opcao, "Digite a opcao desejada: ", 0, 5);

    switch (opcao)
    {
    case SAIR_MENU_DOS_MENUS:
    {
      break;
    }
    case MENU_CLIENTE:
    {
      menuCliente();
      break;
    }
    case MENU_ROTA_ENTREGA:
    {
      menuRotaEntrega();
      break;
    }
    case MENU_SEGUNDA_ENTREGA:
    {
      menuSegundaEntrega();
      break;
    }
    case MENU_DEVOLUCAO:
    {
      menuDevolucao();
      break;
    }
    case MENU_HISTORICO_SCORE:
    {
      menuHistoricoScore();
      break;
    }
    }
  } while (opcao != 0);
}

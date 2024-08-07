#include <rota_segunda_entrega.h>
#include <devolucao_entrega.h>
#include <stdio.h>
#include <stdlib.h>
#include <print_struct.h>
#include <utils.h>
#include <historico.h>

static int idRoutaSegundaEntregaCont = 1;

void criarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha)
{
  pilha = (PilhaSegundaTentativaEntega *)malloc(sizeof(PilhaSegundaTentativaEntega));
  pilha->topo = NULL;
}

void inserirRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, Produto *produto, int id_rota_original)
{
  SegundaTentativaEntega *novo = (SegundaTentativaEntega *)malloc(sizeof(SegundaTentativaEntega));
  novo->idRota = idRoutaSegundaEntregaCont++;
  novo->idRotaOriginal = id_rota_original;
  novo->produto = produto;
  novo->produto->status = REENTREGAR_A_CLINETE;

  novo->prox = pilha->topo;
  pilha->topo = novo;
}

void removerPedido(PilhaSegundaTentativaEntega *pilha)
{
  (void)pilha;
  // if (pilha == NULL || pilha->topo == NULL)
  // {
  //   printf("A pilha esta vazia ou nao foi inicializada!\n");
  // }
  // else
  // {
  //   int idCliente = pilha->topo->clientes->idCliente;
  //   RotaNaoEfetuada *aux = pilha->topo;
  //   RotaNaoEfetuada *anterior = NULL;

  //   int cont = 0;

  //   while (aux != NULL)
  //   {
  //     if (aux->clientes->idCliente == idCliente)
  //     {
  //       if (anterior == NULL)
  //       {
  //         pilha->topo = aux->prox;
  //       }
  //       else
  //       {
  //         anterior->prox = aux->prox;
  //       }
  //       RotaNaoEfetuada *temp = aux;
  //       aux = aux->prox;
  //       free(temp->clientes);
  //       free(temp);
  //       cont++;
  //     }
  //     else
  //     {
  //       anterior = aux;
  //       aux = aux->prox;
  //     }
  //   }
  //   printf("O cliente com ID %d recebeu %d pedidos.\n", idCliente, cont);
  // }
}

void listarPilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia!\n");
  }
  else
  {
    SegundaTentativaEntega *aux = pilha->topo;
    while (aux != NULL)
    {
      printf("ID do Produto: %d\n", aux->produto->id_produto);
      printProduto(aux->produto, "\t");
      aux = aux->prox;
    }
  }
}

void buscarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota)
{
  (void)pilha;
  (void)idRota;
  // if (pilha == NULL || pilha->topo == NULL)
  // {
  //   printf("A pilha esta vazia!\n");
  //   return;
  // }
  // RotaNaoEfetuada *aux = pilha->topo;
  // while (aux != NULL)
  // {
  //   if (aux->idRota == idRota)
  //   {
  //     printf("Rota encontrada:\n");
  //     printf("ID da Rota: %d, ID do Cliente: %d\n", aux->idRota, aux->clientes->idCliente);
  //     printf("Status da Rota: %s\n", aux->status == ENTREGANDO
  //                                        ? "Entregando"
  //                                    : aux->status == FINALIZADO
  //                                        ? "Entregue"
  //                                        : "Recebendo");
  //     return;
  //   }
  //   aux = aux->prox;
  // }
  // printf("Rota com ID %d nao encontrada.\n", idRota);
}

void editarRotaNaoEfetuada(PilhaSegundaTentativaEntega *pilha, int idRota)
{
  (void)pilha;
  (void)idRota;
  // if (pilha == NULL || pilha->topo == NULL)
  // {
  //   printf("A pilha esta vazia!\n");
  //   return;
  // }
  // RotaNaoEfetuada *aux = pilha->topo;
  // while (aux != NULL)
  // {
  //   if (aux->idRota == idRota)
  //   {
  //     int newStatus;
  //     printf("ID da rota a ser editada: %d\n", aux->idRota);
  //     while (1)
  //     {
  //       printf("Digite o novo status da rota: (0 - Recebendo, 1 - Entregando, 2 - Finalizado)\n");
  //       scanf("%d", &newStatus);
  //       if (newStatus == 0)
  //         aux->status = RECEBENDO;
  //       else if (newStatus == 1)
  //         aux->status = ENTREGANDO;
  //       else if (newStatus == 2)
  //         aux->status = FINALIZADO;
  //       else
  //         continue;
  //       break;
  //     }
  //     aux = aux->prox;
  //   }
  //   else
  //   {
  //     printf("Rota nao efetuada nao encontrada\n");
  //   }
  // }
}

void finalizarSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha, FilaDevolucao *filadevolucao, HistoricoEntrega **historico)
{
  if (pilha == NULL || pilha->topo == NULL)
  {
    printf("A pilha esta vazia!\n");
    return;
  }

  while (pilha->topo != NULL)
  {
    Produto *auxProduto = pilha->topo->produto;
    printf("O produto %d foi entregue para o cliente %d?\n", auxProduto->id_produto, auxProduto->cliente->idCliente);

    printf("1 - Sim\n");
    printf("2 - Não\n");
    int status;
    get_int(&status, "Digite a opção desejada: ", 1, 2);

    if (status == 1)
    {
      printf("O produto %d foi entregue para o cliente %d\n", auxProduto->id_produto, auxProduto->cliente->idCliente);
      adicionaHistorico(auxProduto, historico, pilha->topo->idRotaOriginal);
    }
    else
    {
      printf("O produto %d não foi entregue para o cliente %d\n", auxProduto->id_produto, auxProduto->cliente->idCliente);
      printf("O produto será adicionado a pilha de devolução\n");
      inserirDevolucao(filadevolucao, auxProduto, pilha->topo->idRotaOriginal);
    }
    pilha->topo = pilha->topo->prox;
  }

  pilha->topo = NULL;
}

void freePilhaSegundaTentativaEntega(PilhaSegundaTentativaEntega *pilha)
{
  SegundaTentativaEntega *aux = pilha->topo;
  SegundaTentativaEntega *temp;

  while (aux != NULL)
  {
    temp = aux;
    aux = aux->prox;
    free(temp->produto->cliente);
    free(temp->produto->nome);
    free(temp->produto);
    free(temp);
  }
}
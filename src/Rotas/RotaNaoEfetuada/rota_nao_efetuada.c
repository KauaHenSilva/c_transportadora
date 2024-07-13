#include <rota_nao_efetuada.h>
#include <stdio.h>

void hello_word_rotas_nao_efetuadas()
{
  printf("Hello, World! Rotas não efetuadas\n");
}

void inserirRotaNaoEfetuada(Pilha *pilha, RotaNaoEfetuada *rotaNaoEfetuada){
  RotaNaoEfetuada *novo = malloc(sizeof(RotaNaoEfetuada));
  if(novo == NULL){
    printf("Erro ao alocar memoria\n");
  }else{
  novo = rotaNaoEfetuada;
  novo->ant = pilha->topo;
  pilha->topo = novo; 
  }
}

void finalizarRotaNaoEfetuada(Pilha *pilha){
  RotaNaoEfetuada *rota;
  while(pilha->topo!= NULL){
    rota = pilha->topo;
    pilha->topo = pilha->topo->ant;
    free(rota);
  }
  printf("Rotas nao efetuadas finalizadas\n");
}



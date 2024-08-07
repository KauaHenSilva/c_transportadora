#include "score.h"
#include <stdlib.h>
#include <stdio.h>


ScoreRota *getScore(ScoreRota *score, int idRota)
{
  ScoreRota *aux = score;
  while (aux != NULL)
  {
    if (aux->idRota == idRota)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}

ScoreRota *createScore(ScoreRota *score, int idRota)
{
  ScoreRota *newScore = (ScoreRota *)malloc(sizeof(ScoreRota));
  newScore->ponto = 0;
  newScore->idRota = idRota;
  newScore->prox = NULL;

  if (score == NULL)
  {
    score = newScore;
  }
  else
  {
    ScoreRota *aux = score;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = newScore;
  }

  return score;
}

void exibirScore(HistoricoEntrega *historicoEntrega)
{
  ScoreRota *score = NULL;

  HistoricoEntrega *aux = historicoEntrega;

  while (aux != NULL)
  {

    ScoreRota *scoreAux = getScore(score, aux->idRota);
    if (scoreAux == NULL)
    {
      score = createScore(score, aux->idRota);
      scoreAux = getScore(score, aux->idRota);
    }

    if (aux->produto->status == ENTREGAR_A_CLINETE)
      scoreAux->ponto += 5;
    else if (aux->produto->status == REENTREGAR_A_CLINETE)
      scoreAux->ponto += 3;
    else if (aux->produto->status == DEVOLVER_A_REMETENTE)
      scoreAux->ponto -= 1;

    aux = aux->prox;
  }

  ScoreRota *auxScore = score;
  printf("\nScore por rota:\n");
  while (auxScore != NULL)
  {
    printf("Rota: %d - Ponto: %d\n", auxScore->idRota, auxScore->ponto);
    auxScore = auxScore->prox;
  }

}
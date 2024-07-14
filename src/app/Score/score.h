#pragma once

void hello_word_score();

typedef enum typeScore{
  ENTREGA_PRIMEIRA = 5,
  ENTREGA_SEGUNDA = 3,
  ENTREGA_NAO_EFETUADA = -1
} TypeScore;

typedef struct score{
  int entregasEfetuadasPrimeira; // 5 Pontos
  int entregasEfetuadasSegunda; // 3 Pontos
  int entregasNaoEfetuadas; // subtrair 1 ponto

  int total;
} Score;

extern Score *score;

void adicionarScore(TypeScore typeScore); // Rayssa
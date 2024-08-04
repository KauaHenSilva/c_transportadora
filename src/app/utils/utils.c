#include <utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_int(int *var, char *msg, int min, int max)
{
  int input;
  do
  {
    printf("%s", msg);
    scanf("%d", &input);
    if (input < min || input > max)
    {
      printf("Valor inválido. Digite um valor entre %d e %d.\n", min, max);
    }
    clear_buffer();
  } while (input < min || input > max);
  *var = input;
}

void get_string(char **var, char *msg)
{
  char buffer[100];
  do
  {
    printf("%s", msg);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    *var = (char *)malloc(strlen(buffer) + 1);
    if (*var == NULL)
      perror("Erro ao alocar memória.");

    if (strlen(buffer) == 0)
    {
      printf("Valor inválido. Digite um valor válido.\n");
      continue;
    }
  } while (strlen(buffer) == 0);

  strcpy(*var, buffer);
}

void pause()
{
  printf("Pressione ENTER para continuar...");
  getchar();
}

void clear_buffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

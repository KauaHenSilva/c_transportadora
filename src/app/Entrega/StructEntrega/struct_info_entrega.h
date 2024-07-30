#pragma once

/**
 * @brief Enumeração que representa o status do cliente.
 *
 * Esta enumeração define os possíveis status que um cliente pode ter em relação à entrega.
 *
 * @param ENTREGAR_A_CLINETE O cliente deve receber o produto, ainda nn recebido.
 * @param REENTREGAR_A_CLINETE O cliente deve receber o produto novamente, 2 tentativa.
 * @param DEVOLVER_A_REMETENTE O produto deve ser devolvido ao remetente.
 */
typedef enum statusCliente
{
  ENTREGAR_A_CLINETE = 0,   /**< O cliente deve receber o produto. */
  REENTREGAR_A_CLINETE = 1, /**< O cliente deve receber o produto novamente. */
  DEVOLVER_A_REMETENTE = 2, /**< O produto deve ser devolvido ao remetente. */
} StatusCliente;

typedef struct produto
{
  int id;
  char *nome;
  struct produto *prox;
} Produto;

typedef struct clienteEnvio
{
  int idCliente;
  char *nome;
  char *cpf;
  char *endereco;
  StatusCliente status;
  Produto *produtos;

  struct clienteEnvio *prox;
} ClienteEnvio;

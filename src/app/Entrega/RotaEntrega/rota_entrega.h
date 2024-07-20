#pragma once

#include <struct_rotas_entrega.h>

/**
 * Cria uma nova fila de rota de entrega.
 *
 * @param filaRota O ponteiro para a estrutura da fila de rota.
 */
void criarFilaRota(FilaRota *filaRota);

/**
 * Cria uma rota de entrega.
 *
 * Esta função cria uma rota de entrega com base em uma lista de clientes a serem atendidos.
 *
 * @param rota O ponteiro para a estrutura de dados da rota de entrega.
 * @param clientes O ponteiro para a lista de clientes a serem atendidos.
 */
void creatRota(RotaEntrega *rota, ClienteEnvio *clientes);

/**
 * Insere uma nova rota de entrega na fila de rotas.
 *
 * @param filaRota A fila de rotas de entrega.
 * @param newRota A nova rota de entrega a ser inserida.
 */
void inserirRota(FilaRota *filaRota, RotaEntrega *newRota);

/**
 * Função responsável por listar as rotas de entrega.
 *
 * @param filaRota A fila de rotas de entrega.
 */
void listarRotas(FilaRota *filaRota);

/**
 * Edita uma rota de entrega na fila de rotas.
 *
 * @param filaRota A fila de rotas de entrega.
 * @param idRota O ID da rota a ser editada.
 * @param newRota A nova rota de entrega com as informações atualizadas.
 */
void editarRota(FilaRota *filaRota, int idRota, RotaEntrega *newRota);

/**
 * Retorna a rota de entrega com o ID especificado.
 *
 * @param filaRota A fila de rotas de entrega.
 * @param idRota O ID da rota de entrega desejada.
 * @return Um ponteiro para a rota de entrega encontrada, ou NULL se não for encontrada.
 */
RotaEntrega *retornarRota(FilaRota *filaRota, int idRota);

/**
 * Finaliza uma rota de entrega.
 *
 * Esta função recebe como parâmetro um ponteiro para uma estrutura RotaEntrega e realiza as
 * operações necessárias para finalizar a rota de entrega e
 * atualizando o status da rota.
 *
 * @param rota O ponteiro para a estrutura RotaEntrega que representa a rota a ser finalizada.
 *
 * @return 1 se a rota foi finalizada com sucesso, 0 caso contrário.
 */
int finalizarRota(RotaEntrega *rota);

/**
 * Imprime os detalhes de uma rota de entrega.
 *
 * @param rota A rota de entrega a ser impressa.
 */
void printRota(RotaEntrega *rota);

/**
 * Altera o status de um cliente de envio.
 *
 * Esta função recebe um ponteiro para a estrutura ClienteEnvio e um valor do tipo StatusCliente
 * e altera o status do cliente para o valor especificado.
 *
 * @param cliente O ponteiro para a estrutura ClienteEnvio.
 * @param status O valor do tipo StatusCliente para definir o novo status do cliente.
 */
void alterarStatusCliente(ClienteEnvio *cliente, StatusCliente status);

/**
 * Libera a memória alocada para a fila de rota.
 *
 * @param filaRota A fila de rota a ser liberada.
 */
void freeFilaRota(FilaRota *filaRota);

/**
 * Libera a memória alocada para a rota de entrega.
 *
 * @param rota A rota de entrega a ser liberada.
 */
void freeRotaEntrega(RotaEntrega *rota);
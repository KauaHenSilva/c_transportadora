#pragma once

enum enMenuCliente
{
  SAIR_MENU_CLIENTE,
  CADASTRAR_CLIENTE,
  LISTAR_CLIENTES,
  EDITAR_CLIENTE,
  EXCLUIR_CLIENTE,
  // BUSCAR_CLIENTE,
};

enum enMenuRotaEntrega
{
  SAIR_MENU_ROTA_ENTREGA,
  ADICIONAR_PRODUTO,
  LISTAR_ROTAS,
  INICIAR_ROTA,
  // CADASTRAR_ROTA,
  // EXCLUIR_ROTA,
};

enum enMenuSegundaEntrega
{
  SAIR_MENU_SEGUNDA_ENTREGA,
  LISTAR_SEGUNDA_ENTREGA,
  INICIAR_SEGUNDA_ENTREGA,
};

enum enMenuDevolucao
{
  SAIR_MENU_DEVOLUCAO,
  LISTAR_DEVOLUCAO,
  INICIAR_DEVOLUCAO,
};

enum enMenuHistoricoScore
{
  SAIR_MENU_HISTORICO,
  LISTAR_HISTORICO,
  EXIBIR_SCORE,
};

enum enMenuDosMenus
{
  SAIR_MENU_DOS_MENUS,
  MENU_CLIENTE,
  MENU_ROTA_ENTREGA,
  MENU_SEGUNDA_ENTREGA,
  MENU_DEVOLUCAO,
  MENU_HISTORICO_SCORE,
};

void menuRotaEntrega();
void menuCliente();
void menuSegundaEntrega();
void menuDevolucao();
void menuHistoricoScore();

void menuDosMenus();
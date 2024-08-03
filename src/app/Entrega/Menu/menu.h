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
  CADASTRAR_ROTA,
  LISTAR_ROTAS,
  ADICIONAR_PRODUTO,
  INICIAR_ROTA,
  // EXCLUIR_ROTA,
};

enum enMenuSegundaEntrega
{
  SAIR_MENU_SEGUNDA_ENTREGA,
  LISTAR_SEGUNDA_ENTREGA,
  INICIAR_SEGUNDA_ENTREGA,
};

enum enMenuDosMenus
{
  SAIR_MENU_DOS_MENUS,
  MENU_CLIENTE,
  MENU_ROTA_ENTREGA,
};

void menuRotaEntrega();
void menuCliente();
void menuSegundaEntrega();

void menuDosMenus();
inc_struct_entrega       = include_directories('StructEntrega')
inc_cliente_entrega      = include_directories('ClientesEntrega')
inc_rota_entrega         = include_directories('RotaEntrega')
inc_rota_segunda_entrega = include_directories('RotaSegundaEntrega')
inc_devolucao_entrega    = include_directories('DevolucaoEntrega')

subdir('ClientesEntrega')
subdir('RotaEntrega')
subdir('RotaSegundaEntrega')
subdir('DevolucaoEntrega')
subdir('StructEntrega')

inc_entrega = [
  inc_cliente_entrega,
  inc_rota_entrega,
  inc_rota_segunda_entrega,
  inc_devolucao_entrega,
  inc_struct_entrega,
]

lib_entrega = [
  lib_cliente_entrega,
  lib_rota_entrega,
  lib_rota_segunda_entrega,
  lib_devolucao_entrega,
]
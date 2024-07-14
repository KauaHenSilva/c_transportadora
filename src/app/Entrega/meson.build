inc_struct_rotas        = include_directories('StructEntrega')
inc_rota_entrega         = include_directories('RotaEntrega')
inc_rota_segunda_entrega = include_directories('RotaSegundaEntrega')
inc_devolucao_entrega    = include_directories('DevolucaoEntrega')

subdir('RotaEntrega')
subdir('RotaSegundaEntrega')
subdir('DevolucaoEntrega')
subdir('StructEntrega')

includes_entrega = [
  inc_rota_entrega,
  inc_rota_segunda_entrega,
  inc_devolucao_entrega,
  inc_struct_entrega,
]

lib_entrega = [
  lib_rota_entrega,
  lib_rota_segunda_entrega,
  lib_devolucao_entrega,
]
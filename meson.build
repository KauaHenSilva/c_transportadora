project(
  'Tranportadora',
  'c',
  version: '0.1',
  default_options: ['warning_level=3'],
)

subdir('src/Clientes')
subdir('src/Devolucao')
subdir('src/Rotas')
subdir('src/Score')

inc = [inc_cliente]
inc += inc_devolucao
inc += includes_rotas
inc += inc_score

libs = [lib_cliente]
libs += lib_devolucao
libs += lib_rotas
libs += lib_score

executable(
  'Tranportadora',
  'src/main.c',
  link_with: libs,
  include_directories: inc,
  install: true,
)
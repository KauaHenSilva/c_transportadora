project(
  'Tranportadora',
  'c',
  version: '0.1',
  default_options: ['warning_level=3'],
)

subdir('src/app/Entrega')

inc     = [inc_entrega]
inc += inc_score

libs     =  [lib_entrega]
libs += lib_score


executable(
  'Tranportadora',
  'src/main.c',
  link_with: libs,
  include_directories: inc,
  install: true,
)

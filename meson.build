project(
  'Tranportadora',
  'c',
  version: '0.1',
  default_options: ['warning_level=3'],
)

subdir('src/app/utils')
subdir('src/app/Entrega')

inc = [inc_utils]
inc += inc_entrega

libs = [lib_utils]
libs += lib_entrega

executable(
  'Tranportadora',
  'src/main.c',
  link_with: libs,
  include_directories: inc,
  install: true,
)
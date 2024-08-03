inc_score = include_directories('.')

lib_score = static_library(
  'score',
  'score.c',
  include_directories: [
    inc_score,
    inc_struct_entrega,
  ],
  install: true,
)
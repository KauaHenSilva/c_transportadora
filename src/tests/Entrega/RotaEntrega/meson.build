
test_names = [
  'criarFilaRota',
  'inserirRota',
  'finalizarRota',
  'editarRota',
  'retornarRota',
]

foreach test_name : test_names
  test(
    test_name,
    executable(
      test_name,
      test_name + '.c',
      include_directories: [inc, inc_utils],
      link_with: [libs, lib_utils],
    ),
    env: [
      'MALLOC_PERTURB_=0',
    ],
  )
endforeach

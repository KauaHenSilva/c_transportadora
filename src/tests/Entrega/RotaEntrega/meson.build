
test_names = [
  '1_criarFilaRota',
  '2_creatRota',
  '3_inserirRota',
  '4_listarRotas',
  '5_editarRota',
  '6_retornarRota',
  '7_finalizarRota',
]

foreach test_name : test_names
  test(
    'RotaEntrega.c - ' + test_name,
    executable(
      test_name,
      test_name + '.c',
      include_directories: [inc, inc_utils],
      link_with: [libs, lib_utils],
    ),
    env: [
      'MALLOC_PERTURB_=1',
    ],
  )
endforeach

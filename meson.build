project(
  '.marvin',
  'c',
  meson_version : '>= 0.56.0',
  version : '0.0.1',
  license : 'GNU',
  default_options : ['warning_level=3', 'optimization=3'],
)

inc = [include_directories('includes')]

sources = [
  'main.c',
  'src/utils/alloc.c',
  'src/utils/printable.c',
  'src/utils/wraping.c',
  'src/cmd/cmd_help.c',
  'src/cmd/cmd_say.c',
  'src/cmd/cmd_update.c',
]

marvin = executable(
  'marvin',
  sources,
  include_directories : inc,
)

summary({'bindir': get_option('bindir')}, section: 'Directories')

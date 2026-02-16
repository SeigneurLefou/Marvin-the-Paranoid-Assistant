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
  'src/alloc.c',
  'src/printable.c',
  'src/wraping.c',
  'cmd/cmd_help.c',
  'cmd/cmd_say.c',
  'cmd/cmd_update.c',
]

marvin = executable(
  'marvin',
  sources,
  include_directories : inc,
)

summary({'bindir': get_option('bindir')}, section: 'Directories')

project(
  '.marvin',
  'c',
  meson_version : '>= 0.56.0',
  version : '0.0.1',
  license : 'GNU',
  default_options : ['warning_level=3', 'optimization=3'],
)

fs = import('fs')

inc = [include_directories('includes')]

sources = [
  'src/alloc.c',
  'src/printable.c',
  'src/wraping.c',
  'cmd/cmd_help.c',
  'cmd/cmd_say.c',
  'cmd/cmd_update.c',
]

foreach file : command
  name_command = fs.stem(file)
  name_command = name_command.substring(4)
  message(name_command)
  cmd_sources  = [
    file,
    sources,
  ]
  executable(
    name_command,
    cmd_sources,
    include_directories: inc,
  )
  list_command += name_command
endforeach

sources += 'main.c'

marvin = executable(
  'marvin',
  sources,
  include_directories : inc,
)

summary({'bindir': get_option('bindir')}, section: 'Directories')
summary({'Commande build' : list_command}, section: 'Configuartion')

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
  'src/warping.c',
  'src/cmd_help.c',
  'src/cmd_update.c',
]

command = [
  'cmd/cmd_say.c',
]

list_command = []

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
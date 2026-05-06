project(
  'marvin',
  'cpp',
  meson_version : '>= 0.56.0',
  version : '0.0.1',
  license : 'GNU',
  default_options : ['warning_level=3', 'optimization=3'],
)

inc = include_directories('includes')

sources = files(
  'src/main.cpp',
)

marvin = executable(
  'marvin',
  sources,
  include_directories : inc,
)

summary({'bindir': get_option('bindir')}, section: 'Directories')

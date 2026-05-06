#ifndef BUILTINS_HPP
# define BUILTINS_HPP

# include "utils.hpp"

typedef int	(*t_cmd_func) (int argc, char *argv[]);

typedef struct	s_builtin_cmd
{
	string		name;
	t_cmd_func	funct_ptr;
}				t_builtin_cmd;

#endif

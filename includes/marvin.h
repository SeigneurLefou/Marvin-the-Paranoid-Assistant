#ifndef MARVIN_H
# define MARVIN_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

typedef int	(*t_cmd_function) (int argc, char **argv);

typedef struct s_cmd
{
	const char		*name;
	t_cmd_function	fn;
}				t_cmd;

typedef struct s_cmd_path
{
	const char	*name;
	const char	*path;
}			t_cmd_path;


// Builtin Command
int	cmd_help(int argc, char **argv);
int	cmd_update(int argc, char **argv);

// Commands Utils
int	path_cmd(char *argv[], char *env[], char *path);
int	integrate_cmd(int argc, char *argv[]);

// Functions Utils
int		bubble(char *str, size_t size_len, int fd);
char	*lenfill(const char *str, char c, size_t len);
char	*setalloc(char c, size_t len);

#endif

#include "marvin.h"
#include "global_variable.h"

int	path_cmd(char *argv[], char *env[], char *path)
{
	char	*cmd_path;
	pid_t	pid;

	cmd_path = malloc(strlen(getenv("HOME"))
			+ strlen(path) + strlen(argv[1]) + 2);
	if (!cmd_path)
		return (-1);
	strcpy(cmd_path, getenv("HOME"));
	strcat(cmd_path, path);
	strcat(cmd_path, argv[1]);
	if (!access(cmd_path, X_OK))
	{
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			execve(cmd_path, argv + 1, env);
			exit(0);
		}
		waitpid(pid, NULL, 0);
		free(cmd_path);
		return (0);
	}
	free(cmd_path);
	return (-1);
}

int	integrate_cmd(int argc, char *argv[])
{
	char	*cmd;
	t_cmd	*cmd_list;

	cmd = argv[1];
	cmd_list = g_commands_list;
	while (cmd_list->name)
	{
		if (!strcmp(cmd, cmd_list->name))
			return (cmd_list->fn(argc - 1, argv + 1));
		cmd_list++;
	}
	return (-1);
}

int	main(int argc, char *argv[], char *env[])
{
	int	result_cmd;

	if (argc < 2)
		return (1);
	result_cmd = integrate_cmd(argc, argv);
	if (result_cmd >= 0)
		return (result_cmd);
	result_cmd = path_cmd(argv, env, "/.marvin/usr/bin/");
	if (result_cmd >= 0)
		return (result_cmd);
	result_cmd = path_cmd(argv, env, "/.marvin/bin/");
	if (result_cmd >= 0)
		return (result_cmd);
	printf("Command doesn't exist.\n");
	return (1);
}

#include "marvin.h"

int	cmd_update(int argc, char **argv)
{
	char	*home;
	char	*command;

	home = getenv("HOME");
	if (!home)
		return (1);
	command = malloc(strlen("make -C ") + strlen(home)
			+ strlen("/.marvin update") + 1);
	strcpy(command, "make -C ");
	strcat(command, home);
	strcat(command, "/.marvin update");
	system(command);
	free(command);
	if (!command)
		return (1);
	return (0);
}

#include "marvin.h"

int	cmd_update(int argc, char **argv)
{
	char	*marv;
	char	*command;

	marv = getenv("MARV");
	if (!marv)
		return (1);
	command = malloc(strlen("make -C ") + strlen(marv)
			+ strlen(" update") + 1);
	strcpy(command, "make -C ");
	strcat(command, marv);
	strcat(command, " update");
	system(command);
	free(command);
	if (!command)
		return (1);
	return (0);
}

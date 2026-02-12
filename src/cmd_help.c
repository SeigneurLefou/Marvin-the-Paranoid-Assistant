#include "libcmd.h"

int	cmd_help(int argc, char **argv)
{
	write(1, "help", 4);
	return (0);
}

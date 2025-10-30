#include "libft.h"

int main(int argc, char **argv)
{
	(void)argc;
	if (!ft_strcmp(argv[1], "-h"))
	{
		write(1, "help", 5);
		return (0);
	}
	return (0);
}
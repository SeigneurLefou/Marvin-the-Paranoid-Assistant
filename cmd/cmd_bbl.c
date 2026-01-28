#include "libcmd.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*txt;
	char	*emot;
	int		llen;
	int		fd;

	i = 1;
	txt = "Hello, my name is Marvin and I\'m the Paranoid Assistant";
	emot = "neutral";
	llen = 30;
	fd = 1;
	while (argv[i] && i < argc)
	{
		if ((!strcmp(argv[i], "-t")
			|| strcmp(argv[i], "--text")) && argv[i + 1])
			txt = argv[i + 1];
		i++;
	}
	bbl(txt, emot, llen, fd);
	return (0);
}

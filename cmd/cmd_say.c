#include "marvin.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*txt;
	int		line_size;
	int		fd;

	i = 1;
	line_size = 30;
	fd = 1;
	while (i < argc)
	{
		if ((!strcmp(argv[i], "-h")
				|| !strcmp(argv[i], "--help")) && argv[i + 1])
		{
			printf("SAY :\n\tA command to make Marvin talk.\nOPTIONS :\n\t-h/--help : print this help\n\t-ls/--linesize : Define a lline size for the bubble.\nUSAGE\n\tmarvin say content [-ls/--linesize size]");
			return (0);
		}
		else if ((!strcmp(argv[i], "-ls")
				|| !strcmp(argv[i], "--linesize")) && argv[i + 1])
		{
			i++;
			line_size = atoi(argv[i]);
			if (line_size > 80) // Modifier pour que ca s'adapte a la taille du terminal
				line_size = 80;
		}
		else if (!txt)
			txt = argv[i];
		else
		{
			txt = "Les arguments de votre commande sont invalides.";
			bubble(txt, line_size, 2);
			return (1);
		}
		i++;
	}
	if (!txt)
		txt = "Les arguments de votre commande sont invalides.";
	bubble(txt, line_size, fd);
	return (0);
}

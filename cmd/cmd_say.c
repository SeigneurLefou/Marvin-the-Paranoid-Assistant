#include "marvin.h"

int	cmd_say(int argc, char **argv)
{
	int		i;
	char	*txt;
	int		line_size;
	bool	txt_is_define;

	i = 1;
	txt = "Les arguments de votre commande sont invalides.\0";
	txt_is_define = false;
	line_size = 30;
	while (i < argc)
	{
		if ((!strcmp(argv[i], "-h")
				|| !strcmp(argv[i], "--help")))
		{
			printf("SAY :\n\tA command to make Marvin talk.\nOPTIONS :\n\t-h/--help : print this help\n\t-ls/--linesize : Define a lline size for the bubble.\nUSAGE\n\tmarvin say content [-ls/--linesize size]");
			return (0);
		}
		else if ((!strcmp(argv[i], "-ls")
				|| !strcmp(argv[i], "--linesize")) && argv[i + 1])
		{
			i++;
			line_size = atoi(argv[i]);
			if (line_size > 80)
				line_size = 80;
		}
		else if (!txt_is_define)
		{
			txt = argv[i];
			txt_is_define = true;
		}
		else
		{
			printf("SAY :\n\tA command to make Marvin talk.\nOPTIONS :\n\t-h/--help : print this help\n\t-ls/--linesize : Define a lline size for the bubble.\nUSAGE\n\tmarvin say content [-ls/--linesize size]");
			return (0);
		}
		i++;
	}
	bubble_printer(txt, line_size, 1);
	return (0);
}

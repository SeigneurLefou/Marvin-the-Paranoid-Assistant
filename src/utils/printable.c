#include "marvin.h"


int	bubble_printer(char *str, size_t size_len, int fd)
{
	size_t	len;
	char	*fillstr;
	char	**sentences;
	int		i;

	if (strlen(str) < size_len)
	{
		write(fd, str, strlen(str));
		return (0);
	}
	sentences = cut_sentences(str, size_len);
	i = 0;
	while (sentences && sentences[i])
	{
		fillstr = centralize_text(sentences[i], ' ', size_len);
		write(fd, fillstr, strlen(fillstr));
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}

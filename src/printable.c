#include "libft.h"

int	bubble(char *str, size_t size_len, int fd)
{
	size_t	len;
	char	*fillstr;

	len = strlen(str);
	fillstr = lenfill(str, ' ', len);
	write(fd, fillstr, len);
	return (0);
}

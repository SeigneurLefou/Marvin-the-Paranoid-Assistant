#include "marvin.h"

int	bubble(char *str, size_t size_len, int fd)
{
	size_t	len;
	char	*fillstr;

	(void)size_len;
	len = strlen(str);
	fillstr = lenfill(str, ' ', len);
	write(fd, fillstr, len);
	return (0);
}

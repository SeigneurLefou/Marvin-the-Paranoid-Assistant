#include "marvin.h"

int	bubble(char *str, size_t size_len, int fd)
{
	size_t	len;
	char	*fillstr;
	
	len = strlen(str);
	if (len < size_len)
		len = size_len;
	fillstr = lenfill(str, ' ', len);
	write(fd, fillstr, strlen(fillstr));
	return (0);
}

#include "libft.h"

int ft_strcmp(char *str, char *cmp)
{
{
	size_t	i;

	i = 0;
	while (str[i] || cmp[i])
	{
		if (str[i] != cmp[i])
			return (str[i] - cmp[i]);
		i++;
	}
	return (0);
}
}
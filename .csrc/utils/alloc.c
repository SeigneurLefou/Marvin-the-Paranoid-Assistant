#include "marvin.h"

char	*set_alloc(char c, size_t len)
{
	char	*res;

	res = calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	memset(res, c, len);
	return (res);
}

void	*ft_alloc_char(char *s1, char *s2)
{
	size_t	len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len = strlen(s1);
	len += strlen(s2);
	res = calloc(len + 1, sizeof(char));
	return (res);
}

char	*strjoin(char *s1, char *s2)
{
	char	*joinstr;
	size_t	i;
	size_t	j;

	joinstr = ft_alloc_char(s1, s2);
	if (!joinstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		joinstr[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		joinstr[i] = s2[j];
		i++;
		j++;
	}
	return (joinstr);
}

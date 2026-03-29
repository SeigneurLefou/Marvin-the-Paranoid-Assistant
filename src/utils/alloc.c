#include "marvin.h"

void	free_double_array(char **array)
{
	if (!array)
		return ;
	for (size_t i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

char	*set_alloc(char c, size_t len)
{
	char	*res;

	res = calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	memset(res, c, len);
	return (res);
}

char	**append_to_str_array(char **array, char *str)
{
	int		i;
	char	**new_array;
	int		len;

	len = 0;
	while (array && array[len])
		len++;
	new_array = calloc(sizeof(char *), len + 2);
	for (i = 0; i < len; i++)
		new_array[i] = strdup(array[i]);
	new_array[i] = strdup(str);
	free_double_array(array);
	free(str);
	return (new_array);
}

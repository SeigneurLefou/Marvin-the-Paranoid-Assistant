#include "marvin.h"

size_t	double_array_len(char **array)
{
	size_t	len;

	len = 0;
	while (array && array[len])
		len++;
	return (len);
}

void	free_double_array(char **array)
{
	if (!array)
		return ;
	for (size_t i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

char	**append_to_str_array(char **array, char *str)
{
	size_t	i;
	char	**new_array;
	size_t	len;

	len = double_array_len(array);
	new_array = calloc(sizeof(char *), len + 2);
	for (i = 0; i < len; i++)
		new_array[i] = strdup(array[i]);
	new_array[i] = strdup(str);
	free_double_array(array);
	return (new_array);
}

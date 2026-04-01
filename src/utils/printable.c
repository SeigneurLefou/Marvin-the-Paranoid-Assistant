#include "marvin.h"

char	**bubble_create(char **sentences, size_t size_len)
{
	char	**bubble_array;
	size_t	len;
	size_t	index;

	if (!sentences || !(*sentences))
		return (NULL);
	len = double_array_len(sentences);
	bubble_array = calloc(sizeof(char *), len + 5);
	for (size_t i = 0; i < len + 3; i++)
		bubble_array[i] = calloc(sizeof(char), size_len + 8);
	index = 0;
	strcpy(bubble_array[index], "  ");
	for (size_t i = 0; i < size_len + 4; i++)
		strcat(bubble_array[index], "_");
	strcat(bubble_array[index], " ");
	index++;
	strcpy(bubble_array[index], " /");
	for (size_t i = 0; i < size_len + 4; i++)
		strcat(bubble_array[index], " ");
	strcat(bubble_array[index], "\\");
	index++;
	for (size_t i = 0; i < len; i++)
	{
		strcpy(bubble_array[index], " |  ");
		strcat(bubble_array[index], sentences[i]);
		strcat(bubble_array[index], "  |");
		index++;
	}
	strcpy(bubble_array[index], " \\  ");
	for (size_t j = 0; j < size_len + 2; j++)
		strcat(bubble_array[index], "_");
	strcat(bubble_array[index], "/");
	index++;
	bubble_array[index] = strdup("  |/");
	return (bubble_array);
}

int	bubble_printer(char *str, size_t size_len, int fd)
{
	size_t	len;
	char	*fillstr;
	char	**sentences;
	char	**bubble;
	int		i;

	sentences = cut_sentences(str, size_len);
	i = 0;
	while (sentences && sentences[i])
	{
		sentences[i] = centralize_text(sentences[i], ' ', size_len);
		i++;
	}
	bubble = bubble_create(sentences, size_len);
	i = 0;
	while (bubble && bubble[i])
	{
		i++;
	}
	free_double_array(sentences);
	free_double_array(bubble);
	return (0);
}

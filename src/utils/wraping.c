#include "marvin.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *centralize_text(char *str, char c, size_t len) {
	char	*res;
	size_t	str_len;
    size_t	total_padding;
    size_t	left_padding;
    size_t	right_padding;

	if (!str || !c || len == 0)
		return NULL;
	str_len = strlen(str);
    if (str_len >= len)
	{
		res = strdup(str);
		free(str);
        return res;
    }
    total_padding = len - str_len;
    left_padding = total_padding / 2;
    right_padding = total_padding - left_padding;
    res = calloc(1, total_padding + str_len + 1);
    if (!res)
        return NULL;

    for (size_t i = 0; i < left_padding; i++)
        res[i] = c;
    strcpy(&res[left_padding], str);
	printf("%s\n", str);
	free(str);
    for (size_t i = 0; i < right_padding; i++)
        res[left_padding + str_len + i] = c;
    return (res);
}

int	take_line(char *str, char **to_add, unsigned int line_size)
{
	uint	index_start;
	uint	index_end;
	uint	third_index;
	uint	str_len;
	int		breaker;

	index_start = 0;
	index_end = line_size;
	str_len = strlen(str);
	breaker = 0;
	if (index_end > str_len)
	{
		index_end = str_len;
		breaker = 1;
	}
	if (breaker)
	{
		*to_add = calloc(sizeof(char), index_end - index_start + 1);
		memcpy(*to_add, &str[index_start], index_end - index_start );
		return (0);
	}
	while (str && str[index_start] && index_start < index_end && str[index_start] == ' ')
		index_start++;
	third_index = index_end;
	while (str && str[third_index] && index_start < third_index && str[third_index] != ' ')
		third_index--;
	if (index_start >= third_index)
	{
		*to_add = calloc(sizeof(char), index_end - index_start + 1);
		memcpy(*to_add, &str[index_start], index_end - index_start - 1);
		strcat(*to_add, "-");
		return (index_end - 1);
	}
	*to_add = calloc(sizeof(char), third_index - index_start + 1);
	memcpy(*to_add, &str[index_start], third_index - index_start);
	return (third_index + 1);
}

char	**cut_sentences(char *str, unsigned int line_size)
{
	char	**res;
	char	*to_add;
	uint	len_end;
	uint	str_len;


	res = NULL;
	len_end = 0;
	str_len = strlen(str);
	while (str[0])
	{
		len_end = take_line(str, &to_add, line_size);
		res = append_to_str_array(res, to_add);
		free(to_add);
		if (!len_end)
			break;
		str = &str[len_end];
	}
	return (res);
}

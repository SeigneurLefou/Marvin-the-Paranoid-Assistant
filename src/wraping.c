#include "marvin.h"

char	*centralize_text(const char *str, char c, size_t len)
{
	size_t	slen;
	char	*res;
	char	*post;

	if (!str || !c)
		return (NULL);
	slen = strlen(str);
	if (len > slen)
		slen = len;
	res = set_alloc(c, (slen - strlen(str)) / 2);
	if ((slen - strlen(str)) % 2)
		post = set_alloc(c, (slen - strlen(str)) / 2 + 1);
	else
		post = set_alloc(c, (slen - strlen(str)) / 2);
	strcat(res, str);
	strcat(res, post);
	return (res);
}

int	take_line(char *str, char **to_add, unsigned int line_size)
{
	uint	index_start;
	uint	index_end;
	uint	str_len;
	int		breaker;

	index_start = 0;
	index_end = line_size - 1;
	str_len = strlen(str);
	if (index_end > str_len)
	{
		index_end = str_len - 1;
		breaker = 0;
	}
	while (str[index_start] && index_start < index_end && str[index_start] == ' ')
		index_start++;
	while (str[index_end] && str[index_end + 1] && index_start < index_end
		&& !(str[index_end] != ' ' && (str[index_end + 1] == ' ' )))
		index_end--;
	*to_add = calloc(sizeof(char), index_end - index_start + 1);
	memcpy(*to_add, &str[index_start], index_end - index_start + 1);
	if (!breaker)
		return (0);
	return (index_end + 1);
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
	if (str_len < line_size)
	{
		res = calloc(sizeof(char *), 2);
		res[0] = str;
		return (res);
	}
	while (str[len_end])
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

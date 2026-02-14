#include "marvin.h"

char	*centralize_text(const char *str, char c, size_t len)
{
	size_t	slen;
	char	*res;
	char	*pre;
	char	*post;

	if (!str || !c)
		return (NULL);
	slen = strlen(str);
	if (len > slen)
		slen = len;
	res = set_alloc(c, (slen - strlen(str)) / 2);
	post = set_alloc(c, (slen - strlen(str)) / 2);
	strcat(res, str);
	strcat(res, post);
	return (res);
}

char	**cut_sentences(char *str, unsigned int line_size)
{
	char	**res;
	char	*to_add;
	uint	counter_line;
	uint	index_start;
	uint	index_end;

	counter_line = 1;
	index_start = 0;
	index_end = counter_line * line_size - 1;
	res = NULL;
	if (counter_line * line_size > strlen(str))
	{
		res = calloc(sizeof(char *), 2);
		res[0] = str;
		return (res);
	}
	while (str[index_end])
	{
		to_add = calloc(sizeof(char), index_end - index_start + 1);
		while (str[index_end] && str[index_end] == ' '
			&& (!str[index_end + 1] || str[index_end + 1] != ' '))
			index_end--;
		memcpy(to_add, &str[index_start], index_end - index_start);
		res = append_to_str_array(res, to_add);
		index_start = counter_line * line_size;
		counter_line++;
		index_end = counter_line * line_size - 1;
		if (counter_line * line_size > strlen(str))
			index_end = strlen(str);
	}
	return (res);
}

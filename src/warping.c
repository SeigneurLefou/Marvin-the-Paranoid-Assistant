#include "marvin.h"

char	*lenfill(const char *str, char c, size_t len)
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
	res = setalloc(c, (slen - strlen(str)) / 2);
	post = setalloc(c, (slen - strlen(str)) / 2);
	strcat(res, str);
	strcat(res, post);
	return (res);
}

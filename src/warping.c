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
	res = (char *)str;
	pre = setalloc(c, (slen - strlen(str)) / 2);
	if ((slen - strlen(str)) % 2)
		post = setalloc(c, (slen - strlen(str)) / 2 + 1);
	else
		post = setalloc(c, (slen - strlen(str)) / 2);
	strcat(pre, res);
	strcat(res, post);
	return (res);
}

#include "marvin.h"

char	*setalloc(char c, size_t len)
{
	char	*res;

	res = calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	memset(res, c, len);
	return (res);
}

#include "libft.h"

char	*ft_strjoin_free(char **dst, const char *src,
			size_t dstsize, size_t srcsize)
{
	char *tmp;

	tmp = *dst;
	if (!(*dst = (char *)malloc(sizeof(char) * (dstsize + srcsize + 1))))
			return (NULL);
	ft_strcpy(*dst, tmp);
	ft_strcat(*dst, src);
	free(tmp);
	return (*dst);
}

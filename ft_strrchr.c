#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found;

    if(!s)
        return NULL;
	i = 0;
	found = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			found = i;
		i++;
	}
	if (found != -1)
		return ((char *)s + found);
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

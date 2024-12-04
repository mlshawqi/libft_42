#include "get_next_line.h"

int	ft_str_len(char *s, int sing)
{
	size_t	len;

	if (!s)
		return (-1);
	len = 0;
	if (sing == 1)
	{
		while (s[len] != '\0')
			len++;
		return (len);
	}
	else
	{
		while (s[len])
		{
			if (s[len] == '\n')
				return (len);
			len++;
		}
		return (-1);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(char *s, size_t len)
{
	char	*dup;
	size_t	i;

	if (!s || len == 0)
		return (NULL);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_str_len(s, 1) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lens1 = ft_str_len(s1, 1);
	lens2 = ft_str_len(s2, 1);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + lens1, s2);
	return (str);
}
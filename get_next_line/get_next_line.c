#include "get_next_line.h"

int     newline(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}
char	*ft_strndup(char *s, int len)
{
	char	*dup;
	size_t	i;

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

char *get_next_line(int fd)
{
    ssize_t bytes_read;
    char    buf[100];
    size_t  count = 99;
    char *savebuf = NULL;
    int nline;
    if (fd == -1)
    {
        return (0);
    }

    int o = 0;
    int j = 0;
    while(o == 0)
    {
        bytes_read = read(fd, buf, count);
        if (bytes_read == -1)
        {
            printf("\nhr\n");
            return (0);
        }
        if(bytes_read == 0)
        {
            
        }
        buf[bytes_read] = '\0';
        nline = newline(buf);
        if(nline != -1)
            o++;
        if (j == 0)
        {
            if(nline != -1)
                return (ft_strndup(buf, nline + 1));
            else
                savebuf = ft_strndup(buf, bytes_read);
        }
        else 
        {
            if(o > 0)
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, ft_strndup(buf, nline + 1));
                free(temp);
            }
            else
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, buf);
                free(temp);
            }
        }
        // if(nline != (-1))
        //     
        j++;
    }
    return (savebuf);
}
int main()
{
    int fd = open("text.txt", O_RDONLY);

    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
}
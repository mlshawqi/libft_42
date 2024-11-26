


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
    static ssize_t bytes_read = 0;
    static char buf[1024];
    static int curr_pos = 0; 
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
        if(curr_pos >= bytes_read)
            bytes_read = read(fd, buf, sizeof(buf));
        if (bytes_read == -1)
        {
            printf("\nhr\n");
            return (0);
        }

        buf[bytes_read] = '\0';
        nline = newline(buf);
        if(nline != -1)
            o++;
        if (j == 0)
        {
            if(nline != -1)
            {
                curr_pos = nline;
                return (ft_strndup(buf, nline + 1));
            }
                
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
                if(bytes_read == 0)
                {
                    return (savebuf);
                }
            }
        }
        // if(nline != (-1))
        //     
        j++;
    }
    return (savebuf);
}
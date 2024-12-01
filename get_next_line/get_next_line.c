#include "get_next_line.h"

ssize_t ft_read_fd(int fd, char **buf)
{
    ssize_t byte_rd = 0;
    
    *buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
    if (!(*buf))
        return (-1);
    byte_rd = read(fd, *buf, BUFFER_SIZE);
    if(byte_rd <= 0)
	    return (byte_rd);
    (*buf)[byte_rd] = '\0';
    return (byte_rd);
}

void    ft_free(char **str)
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
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

char    *ft_somthingg(char **buf, char **save, ssize_t rd_byte)
{
    int nline = ft_newline(*buf);

    char    *line = ft_strndup(*buf, nline + 1);
    if(*(*buf + nline) != '\0')
    {
        char *tp = malloc((rd_byte - (nline - 1)) * sizeof(char));
        if(!tp)
            return (NULL);
        ft_strcpy(tp, *buf + nline + 1);
        char *x = *buf;
        *buf = ft_strdup(tp);
        ft_free(&tp);
        free(x);       
    }
    else
        *buf = NULL;

	if(line && (*save) != NULL)
    {    
        char *tmp = ft_strjoin(*save, line);
        ft_free(save);
        free(line);
        return (tmp);
    }
    return (line);
}
void    ft_savebuf(char *buff, char **savebuf)
{
    if(*savebuf != NULL)
    {
        char *tmp = *savebuf;
	    *savebuf = ft_strjoin(*savebuf, buff);
	//printf("\n---------save = %s  pos = %zu---------\n", *savebuf, *pos);
	    free(tmp);
    }
    else
        *savebuf = ft_strdup(buff);
}
char    *ft_tt(ssize_t byte,char **buff, char **savebf)
{
        if (byte <= 0)
        {
            ft_free(buff);
            if (*savebf)
            {
                char *tmp = *savebf;
                ft_free(savebf);
                return tmp;
            }
            return NULL;
        }
}
char *get_next_line(int fd)
{
    static char *buffer;
    ssize_t byte_read;
    char *savebuf;

    if(!fd || !BUFFER_SIZE)
        return (NULL);
    savebuf = NULL;
    while (1)
    {
        if(!buffer)
        {
            byte_read = ft_read_fd(fd, &buffer);
            if(byte_read <= 0)
                return (ft_tt(byte_read, &buffer, &savebuf));            
        }
        if (ft_newline(buffer) != -1)
            return ft_somthingg(&buffer, &savebuf, byte_read);
        else
        {
            ft_savebuf(buffer, &savebuf);
            ft_free(&buffer);
        }
    }
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
    return 0;

}
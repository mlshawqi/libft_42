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
    char    *line;
    char    *tp;
    char    *tmp;

    line = ft_strndup(*buf, nline + 1);
    if(*(*buf + nline) != '\0')
    {
        tp = *buf;
        *buf = ft_strdup(*buf + nline + 1);
        ft_free(&tp);
    }
    else
        ft_free(buf);
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
char    *ft_error(ssize_t byte,char **buff, char *savebf)
{
        if (byte <= 0)
        {
            ft_free(buff);
            if (savebf)
            {
                return (savebf);
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
                return (ft_error(byte_read, &buffer, savebuf));
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
   
    char *str =  get_next_line(fd);
    while(str)
    {
    	printf("%s", str);
	    free(str);
    	str =  get_next_line(fd);
    }
    return 0;

}
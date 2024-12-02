#include "get_next_line.h"

char *ft_read_fd(int fd, char **buf, char **savebf)
{
    ssize_t byte_read = 1;
    char *reminder;
    int nline;
    
    reminder = NULL;
    while(!(*buf))
    {
        buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
        if(!buf)
            return NULL;
        byte_read = read(fd, buf, BUFFER_SIZE);
        if (byte_read <= 0)
        {
            ft_free(buf);
            if (*savebf)
             {
                char *tmp = (*savebf);
                ft_free(savebf);
                return tmp;
            }
            return NULL;
        }
        if(ft_newline(*buf) != -1)
        {
            ft_somthing(*buf);
            break;
        }    
    }

}

void    ft_free(char **str)
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
}
char    *ft_line(char *buff, ssize_t *pos, char **savebuff)
{
    int nline = ft_newline(buff + *pos);

    if(nline != -1)
    {
	    //printf("\nim here\n");
	    char	*line = ft_strndup(buff + *pos, nline + 1);
        *pos += (nline + 1);
	    if(line && (*savebuff) != NULL)
	    {    
            char *tmp = ft_strjoin(*savebuff, line);
            ft_free(savebuff);
            free(line);
            return (tmp);
        }
        return (line);
    }
    return (NULL);
}

void    ft_savebuf(char *buff, ssize_t *pos, char **savebuf, ssize_t read_byte)
{
    if(*savebuf != NULL)
    {
        char *tmp = *savebuf;
	    *savebuf = ft_strjoin(*savebuf, buff + *pos);
	//printf("\n---------save = %s  pos = %zu---------\n", *savebuf, *pos);
	    free(tmp);
    }
    else
        *savebuf = ft_strdup(buff + *pos);
    *pos += read_byte;
}

char *get_next_line(int fd)
{
    static char *buffer;
    ssize_t byte_read;
    char    *savebuf;

    savebuf = NULL;
    reminder = ft_read_fd(fd, &buffer, &savebuf);
}


_____________________________________________________________________________________________________________



















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

    line = ft_strndup(*buf, nline + 1);
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
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return 0;

}
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
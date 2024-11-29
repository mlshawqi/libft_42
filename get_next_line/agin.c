#include "get_next_line.h"

ssize_t ft_read_fd(int fd, char *buf)
{
    ssize_t byte_rd = 0;
    
    byte_rd = read(fd, buf, BUFFER_SIZE);
    buf[byte_rd] = '\0';
    return (byte_rd);
}

char    *ft_line(char *buff, ssize_t *pos, int *j)
{
    int nline = ft_newline(buff + *pos);
    int find = 0;

    if(nline != -1)
        find++;
    if(*j == 0)
    {
        if(find > 0)
        {
            char *line = ft_strndup(buff + *pos, nline + 1);
            *pos += (nline + 1);
            return line;        
        }
        else
        {
            
        }
        (*j)++;
    }
    return (NULL);
}

char    ft_savebuf(char *buff, ssize_t *pos, char **savebuf, ssize_t read_byte)
{
    int nline = ft_newline(buff + *pos);
    if(*savebuf)
    {
        
    }
    else
    {
        *savebuf = ft_strndup(buff + *pos, read_byte - *pos);
        *pos = read_byte;
    }
}

char *get_next_line(int fd)
{
    static char     *buffer;
    static  ssize_t byte_read;
    static  ssize_t position = 0;
    int j = 0;
    char *savebuf = NULL;

    while(1)
    {
        if (position >= byte_read)
        {
            buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
            if(!buffer)
                return NULL;
            byte_read = ft_read_fd(fd, buffer);
            if(byte_read < 0)
            {
                free(buffer);
                return (NULL);
            }
        }

        char    *line = ft_line(buffer, &position, &j);
        if(line)
        {
            free(buffer);
            free(savebuf);
            return (line);
        }
        ft_savebuf(buffer, &position, &savebuf, byte_read);      
    }

}
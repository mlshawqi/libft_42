#include "get_next_line.h"

ssize_t ft_read_fd(int fd, char *buf)
{
    ssize_t byte_rd = 0;
    
    byte_rd = read(fd, buf, BUFFER_SIZE);
    if(byte_rd <= 0)
	    return (byte_rd);
    buf[byte_rd] = '\0';
    return (byte_rd);
}

char    *ft_line(char *buff, ssize_t *pos)
{
    int nline = ft_newline(buff + *pos);

    if(nline != -1)
    {
	    //printf("\nim here\n");
	    char	*line = ft_strndup(buff + *pos, nline + 1);
	    *pos += (nline + 1);
	    return (line);
    }
    return (NULL);
}

char    ft_savebuf(char *buff, ssize_t *pos, char **savebuf, ssize_t read_byte)
{
    int nline = ft_newline(buff + *pos);
    if(*savebuf != NULL)
    {
        char *tmp = *savebuf;
	*savebuf = ft_strjoin(*savebuf, buff + *pos);
	//printf("\n---------save = %s  pos = %zu---------\n", *savebuf, *pos);
	free(tmp);
	*pos = read_byte;
    }
    else
    {
        *savebuf = ft_strdup(buff + *pos);
        *pos = read_byte;
    }
}

char *get_next_line(int fd)
{
    static char     *buffer;
    static  ssize_t byte_read = 0;
    static  ssize_t position = 0;
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
	    position = 0;
	    if(byte_read == 0)
		    return ("hello");
        }
        char    *line = ft_line(buffer + position, &position);
        if(line && savebuf != NULL)
     	{
            free(buffer);
            return (line);
        }
	else if(line)
	{
		char *tmp = ft_strjoin(savebuf, line);
		free(buffer);
		free(savebuf);
		free(line);
		return (tmp);
	}
	else
	{
        	ft_savebuf(buffer + position, &position, &savebuf, byte_read);
		//printf("\nsave = %s  posi = %zu  buf = %s\n", savebuf, position, buffer);
	}
    }

}/*
oeieieiejdjdhfnchfuf
lfmfldmdl
eldmdmldm
lememem*/
int main()
{
    int fd = open("text.txt", O_RDONLY);

    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    //printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    //printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
}
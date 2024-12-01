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
        if
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
        bytes_read = 0;
        curr_pos = 0;
    }
    return (savebuf);
}









______________________________________________________________________________________________






char   *get_next_line(int fd )
{
    static char buf[1024];
    static ssize_t byte_read = 0;
    static ssize_t curr_pos = 0;
    char *savebuf = NULL;
    int nline;
    int o = 0;
    int j = 0;
    while(o == 0)
    {
        if(curr_pos >= byte_read)
        {
            byte_read = read(fd, buf, sizeof(buf));
            if(byte_read < 0)
                return NULL;
            buf[byte_read] = '\0';
            if(byte_read == 0)
                return (buf);
            curr_pos = 0;
        }
        nline = newline(buf + curr_pos);
        if(nline != -1)
            o++;
        if (j == 0)
        {
            if(o > 0)
            {

                curr_pos += (nline + 1);
                printf("\n curr %zu  nline %d byteread %zu\n", curr_pos, nline, byte_read);
                return (ft_strndup(buf + (curr_pos - nline - 1), nline + 1));
            }             
            else
                savebuf = ft_strndup(buf + (curr_pos - nline - 1), byte_read);
        }
        else 
        {
            if(o > 0)
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + (curr_pos - nline - 1), nline + 1));
                free(temp);
            }
            else
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, buf);
                free(temp);
            }
        }
        byte_read = 0;
        curr_pos = 0;
        j++;
    }
    curr_pos += (nline + 1);
    return (savebuf);
}


_____________________________________________________________________________________





#include "get_next_line.h"

char *get_next_line(int fd) {
    static char *buf;
    static ssize_t byte_read = 0;
    static ssize_t curr_pos = 0;
    char *savebuf = NULL;
    int nline;
    int o = 0;
    int j = 0;

    while (o == 0) {
        // If buffer is exhausted, read more data
        if (curr_pos >= byte_read) {
            buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
            byte_read = read(fd, buf, BUFFER_SIZE);
            if (byte_read < 0) { // Handle read errors
                free(savebuf);
                return NULL;
            }
            if (byte_read == 0) { // Handle EOF
                if (savebuf)
                    return savebuf; // Return remaining data
                return NULL;
            }
            buf[byte_read] = '\0'; // Null-terminate safely
            curr_pos = 0;
        }

        // Find newline in the buffer
        nline = ft_newline(buf + curr_pos);
        if (nline != -1)
            o++; // Mark if a newline is found

        // Handle the first iteration
        if (j == 0) {
            if (o > 0) {
                char *line = ft_strndup(buf + curr_pos, nline + 1);
                curr_pos += (nline + 1);
                return line;
            } else {
                savebuf = ft_strndup(buf + curr_pos, byte_read - curr_pos);
                curr_pos = byte_read; // Move to the end of the buffer
            }
        }
        // Handle subsequent iterations
        else {
            char *temp = savebuf;
            if (o > 0) {
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + curr_pos, nline + 1));
                curr_pos += (nline + 1);
            } else {
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + curr_pos, byte_read - curr_pos));
                curr_pos = byte_read;
            }
            free(temp);
        }
        j++;
    }

    return savebuf;
}


int main()
{
    int fd = open("text.txt", O_RDONLY);

    
    printf("\n%s\n", get_next_line(fd));
    //printf("\n%s\n", get_next_line(fd));
    //printf("\n%s\n", get_next_line(fd));
}





_________________________________________________________________________________________











ssize_t ft_read_fd(int fd, char *buf, ssize_t *pos)
{
    ssize_t byte_rd = 0;
    
    byte_rd = read(fd, buf, BUFFER_SIZE);
    if(byte_rd <= 0)
	    return (byte_rd);
    *pos = 0;
    buf[byte_rd] = '\0';
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
    static ssize_t byte_read;
    static ssize_t position;
    char *savebuf = NULL;

    while (1)
    {
        if (position >= byte_read)
        {
            buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
            if (!buffer)
                return NULL;

            byte_read = ft_read_fd(fd, buffer, &position);
            if (byte_read <= 0)
            {
                ft_free(&buffer);
                if (savebuf)
                {
                    char *tmp = savebuf;
                    ft_free(&savebuf);
                    return tmp;
                }
                return NULL;
            }
        }

        char *line = ft_line(buffer + position, &position, &savebuf);
        if (line)
        {
            if (position >= byte_read)
                ft_free(&buffer);
            return line;
        }
        else
        {
            ft_savebuf(buffer + position, &position, &savebuf, byte_read);
            ft_free(&buffer);
        }
    }
}
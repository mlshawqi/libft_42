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

char   *get_next_line(int fd)
{
    static char buf[1024];
    static ssize_t byte_read = 0;
    static ssize_t curr_pos = 0;
    char *savebuf = NULL;
    int nline;
    int o = 0;
    int j = 0;
    static int first = 0;
    while(o == 0)
    {
        if(curr_pos >= byte_read)
        {
            byte_read = read(fd, buf, sizeof(buf));
            if(byte_read < 0)
                return NULL;
            buf[byte_read] = '\0';
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
                if(first == 0)
                {
                    first++;
                    return (ft_strndup(buf, nline + 1));
                }
                printf("\n curr %zu  nline %d byteread %zu\n", curr_pos, nline, byte_read);
                return (ft_strndup(buf + (curr_pos - nline), nline + 1));
            }             
            else
                savebuf = ft_strndup(buf, byte_read);
        }
        else 
        {
            if(o > 0)
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + curr_pos, nline + 1));
                free(temp);
            }
            else
            {
                char *temp = savebuf;
                savebuf = ft_strjoin(savebuf, buf);
                free(temp);
            }
        }
        j++;
    }
    curr_pos += (nline + 1);
    return (savebuf);
}
int main()
{
    int fd = open("text.txt", O_RDONLY);

    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
    printf("\n%s\n", get_next_line(fd));
}
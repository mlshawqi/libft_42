#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
    char    buf[50];
    size_t  count = 49;
    char *tmp;

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
        buf[bytes_read] = '\0';
        int nline = newline(buf);
        if(nline != (-1))
        (
            return (ft_strndup(buf, nline + 1));
            o++;
        )
        else
        (
            if(j == 0)
                char *savebuf = ft_strndup(buf, bytes_read);
            else
            {
                savebuf = ft_strjoin(savebif, buf);
            }

        )
    }
    else
        return(get_next_line(fd));
}
int main()
{
    int fd = open("text.txt", O_RDONLY);

    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
    printf("\nfd = %d\n%s\n", fd, get_next_line(fd));
}
#include "get_next_line_bonus.h"

static ssize_t	ft_read_fd(int fd, char **buf)
{
	ssize_t	byte_rd;

	byte_rd = 0;
	*buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!(*buf))
		return (-1);
	byte_rd = read(fd, *buf, BUFFER_SIZE);
	if (byte_rd <= 0)
		return (byte_rd);
	(*buf)[byte_rd] = '\0';
	return (byte_rd);
}

static void	ft_save_free_str(char **str, char *buff, char **savebuf, int sing)
{
	char	*tmp;

	if (sing == 1)
	{
		if (*savebuf != NULL)
		{
			tmp = *savebuf;
			*savebuf = ft_strjoin(*savebuf, buff);
			free(tmp);
		}
		else
			*savebuf = ft_strdup(buff);
	}
	else
	{
		if (str && *str)
		{
			free(*str);
			*str = NULL;
		}
	}
}

static char	*ft_newbuf(char **buf, char **save)
{
	int		nline;
	char	*line;
	char	*tp;
	char	*tmp;

	nline = ft_str_len(*buf, 0);
	line = ft_strndup(*buf, nline + 1);
	if (*(*buf + nline) != '\0')
	{
		tp = *buf;
		*buf = ft_strdup(*buf + nline + 1);
		ft_save_free_str(&tp, NULL, NULL, 0);
	}
	else
		ft_save_free_str(buf, NULL, NULL, 0);
	if (line && (*save) != NULL)
	{
		tmp = ft_strjoin(*save, line);
		ft_save_free_str(save, NULL, NULL, 0);
		free(line);
		return (tmp);
	}
	return (line);
}

static char	*ft_error(ssize_t byte, char **buff, char *savebf)
{
	if (byte <= 0)
	{
		ft_save_free_str(buff, NULL, NULL, 0);
		if (savebf)
			return (savebf);
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	ssize_t		byte_read;
	char		*savebuf;

	if (!fd || !BUFFER_SIZE)
		return (NULL);
	savebuf = NULL;
	while (1)
	{
		if (!buffer[fd])
		{
			byte_read = ft_read_fd(fd, &buffer[fd]);
			if (byte_read <= 0)
				return (ft_error(byte_read, &buffer[fd], savebuf));
		}
		if (ft_str_len(buffer[fd], 0) != -1)
			return (ft_newbuf(&buffer[fd], &savebuf));
		else
		{
			ft_save_free_str(NULL, buffer[fd], &savebuf, 1);
			ft_save_free_str(&buffer[fd], NULL, NULL, 0);
		}
	}
}
int	main(void)
{
	int		fd1;
        int		fd2;
        int		fd3;
        int		fd4;
	char	*str1;
        char	*str2;
        char	*str3;
        char	*str4;

	fd1 = open("text1.txt", O_RDONLY);
        fd2 = open("text2.txt", O_RDONLY);
        fd3 = open("text3.txt", O_RDONLY);
        fd4 = open("text4.txt", O_RDONLY);
	str1 = get_next_line_bonus(fd1);
        str2 = get_next_line_bonus(fd2);
        str3 = get_next_line_bonus(fd3);
        str4 = get_next_line_bonus(fd4);
	while ((str1 || str2) || (str3 || str4))
	{
		printf("%s", str1);
		free(str1);
		str1 = get_next_line_bonus(fd1);

		printf("%s", str2);
		free(str2);
		str2 = get_next_line_bonus(fd2);
		
                printf("%s", str3);
		free(str3);
		str3 = get_next_line_bonus(fd3);
		
                printf("%s", str4);
		free(str4);
		str4 = get_next_line_bonus(fd4);
	}
	return (0);
}
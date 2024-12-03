#include "get_next_line.h"

ssize_t	ft_read_fd(int fd, char **buf)
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

void	ft_save_free_str(char **str, char *buff, char **savebuf, int sing)
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

char	*ft_newbuf(char **buf, char **save)
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

char	*ft_error(ssize_t byte, char **buff, char *savebf)
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		byte_read;
	char		*savebuf;

	if (!fd || !BUFFER_SIZE)
		return (NULL);
	savebuf = NULL;
	while (1)
	{
		if (!buffer)
		{
			byte_read = ft_read_fd(fd, &buffer);
			if (byte_read <= 0)
				return (ft_error(byte_read, &buffer, savebuf));
		}
		if (ft_str_len(buffer, 0) != -1)
			return (ft_newbuf(&buffer, &savebuf));
		else
		{
			ft_save_free_str(NULL, buffer, &savebuf, 1);
			ft_save_free_str(&buffer, NULL, NULL, 0);
		}
	}
}
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}
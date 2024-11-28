#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
static char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int newline(char *str);
char *ft_strndup(char *s, size_t len);

#endif
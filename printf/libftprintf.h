#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int    ft_putstr(char *str);
int     ft_printf(const char *format, ...);
void	    ft_putnbr(int n, int *cn);
int     ft_putchar(char c);
int ft_format(const char **fr, va_list args);

#endif
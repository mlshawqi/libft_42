#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void		ft_decimal(unsigned int n, int *len);
void		ft_format(const char **fr, va_list args, int *cnt);
void		ft_hexalow(unsigned int nbr, int *len);
void		ft_hexaupp(unsigned int nbr, int *len);
void		ft_pointer(void *ptr, int *len);
int			ft_printf(const char *argument, ...);
void		ft_putchar(char c, int *len);
void		ft_putnbr(long n, int *len);
void		ft_putstr(char *str, int *len);

#endif
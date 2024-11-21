#include "ft_printf.h"

void	ft_format(const char **fr, va_list args, int *cnt)
{
	(*fr)++;
	if (!**fr)
		*cnt = -1;
	else if (**fr == 'd' || **fr == 'i')
		ft_putnbr(va_arg(args, int), cnt);
	else if (**fr == 's')
		ft_putstr(va_arg(args, char *), cnt);
	else if (**fr == 'c')
		ft_putchar((char)va_arg(args, int), cnt);
	else if (**fr == 'u')
		ft_decimal(va_arg(args, unsigned int), cnt);
	else if (**fr == 'x')
		ft_hexalow(va_arg(args, unsigned int), cnt);
	else if (**fr == 'X')
		ft_hexaupp(va_arg(args, unsigned int), cnt);
	else if (**fr == 'p')
		ft_pointer(va_arg(args, void *), cnt);
	else if (**fr == '%')
		ft_putchar('%', cnt);
	else
		ft_putchar(**fr, cnt);
}
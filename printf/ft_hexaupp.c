#include "ft_printf.h"

void	ft_hexaupp(unsigned int nbr, int *len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_hexaupp((nbr / 16), len);
		ft_hexaupp((nbr % 16), len);
	}
	else
		ft_putchar(base[nbr], len);
}
#include "ft_printf.h"

void	ft_hexalow(unsigned int nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr % 16], len);
	else
	{
		ft_hexalow((nbr / 16), len);
		ft_hexalow((nbr % 16), len);
	}
}
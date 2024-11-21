#include "ft_printf.h"

void	ft_hexdecimal(unsigned long nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr % 16], len);
	else
	{
		ft_hexdecimal((nbr / 16), len);
		ft_hexdecimal((nbr % 16), len);
	}
}

void	ft_pointer(void *ptr, int *len)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (!addr)
	{
		ft_putstr("0x0", len);
		return ;
	}
	ft_putstr("0x", len);
	if (*len == -1)
		return ;
	if (addr == 0)
		ft_putchar('0', len);
	else
		ft_hexdecimal(addr, len);
}

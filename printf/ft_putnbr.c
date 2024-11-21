#include "ft_printf.h"

void	ft_putnbr(long n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		if (*len == -1)
			return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
		ft_putnbr(n, len);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), len);
		ft_putnbr((n % 10), len);
	}
	else
		ft_putchar(n + '0', len);
}
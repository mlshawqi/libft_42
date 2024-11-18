#include "libftprintf.h"

void	ft_putnbr(int n, int *cn)
{
	if(n == -2147483648)
		*cn += ft_putstr("-2147483648");
	else if(n < 0)
	{
		*cn += ft_putchar('-');
		n *= -1;
		ft_putnbr(n, cn);
	}
	else if(n > 9)
	{
		ft_putnbr((n / 10), cn);
		ft_putnbr((n % 10), cn);
	}
	else
		*cn += ft_putchar(n + '0');
}